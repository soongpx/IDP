import time
import datetime
import platform
import struct
import lib.device_model as deviceModel
from lib.data_processor.roles.jy901s_dataProcessor import JY901SDataProcessor
from lib.protocol_resolver.roles.wit_protocol_resolver import WitProtocolResolver

welcome = """
欢迎使用维特智能示例程序
"""
_writeF = None                    #写文件
_IsWriteF = False                 #写文件标识

def readConfig(device):
    """
    读取配置信息示例
    :param device: 设备模型
    :return:
    """
    tVals = device.readReg(0x02,3)  #读取数据内容、回传速率、通讯速率
    if (len(tVals)>0):
        print("返回结果：" + str(tVals))
    else:
        print("无返回")
    tVals = device.readReg(0x23,2)  #读取安装方向、算法
    if (len(tVals)>0):
        print("返回结果：" + str(tVals))
    else:
        print("无返回")

def setConfig(device):
    """
    设置配置信息示例
    :param device: 设备模型
    :return:
    """
    device.unlock()                # 解锁
    time.sleep(0.1)                # 休眠100毫秒
    device.writeReg(0x03, 6)       # 设置回传速率为10HZ
    time.sleep(0.1)                # 休眠100毫秒
    device.writeReg(0x23, 0)       # 设置安装方向:水平、垂直
    time.sleep(0.1)                # 休眠100毫秒
    device.writeReg(0x24, 0)       # 设置安装方向:九轴、六轴
    time.sleep(0.1)                # 休眠100毫秒
    device.save()                  # 保存

def AccelerationCalibration(device):
    """
    加计校准
    :param device: 设备模型
    :return:
    """
    device.AccelerationCalibration()                 # 加计校准
    print("加计校准结束")

def FiledCalibration(device):
    """
    磁场校准
    :param device: 设备模型
    :return:
    """
    device.BeginFiledCalibration()                   # 开始磁场校准
    if input("请分别绕XYZ轴慢速转动一圈，三轴转圈完成后，结束校准（Y/N)？").lower()=="y":
        device.EndFiledCalibration()                 # 结束磁场校准
        print("结束磁场校准")

def onUpdate(deviceModel):
    """
    数据更新事件
    :param deviceModel: 设备模型
    :return:
    """
    print("芯片时间:" + str(deviceModel.getDeviceData("Chiptime"))
         , " 温度:" + str(deviceModel.getDeviceData("temperature"))
         , " 加速度：" + str(deviceModel.getDeviceData("accX")) +","+  str(deviceModel.getDeviceData("accY")) +","+ str(deviceModel.getDeviceData("accZ"))
         ,  " 角速度:" + str(deviceModel.getDeviceData("gyroX")) +","+ str(deviceModel.getDeviceData("gyroY")) +","+ str(deviceModel.getDeviceData("gyroZ"))
         , " 角度:" + str(deviceModel.getDeviceData("angleX")) +","+ str(deviceModel.getDeviceData("angleY")) +","+ str(deviceModel.getDeviceData("angleZ"))
        , " 磁场:" + str(deviceModel.getDeviceData("magX")) +","+ str(deviceModel.getDeviceData("magY"))+","+ str(deviceModel.getDeviceData("magZ"))
        , " 经度:" + str(deviceModel.getDeviceData("lon")) + " 纬度:" + str(deviceModel.getDeviceData("lat"))
        , " 航向角:" + str(deviceModel.getDeviceData("Yaw")) + " 地速:" + str(deviceModel.getDeviceData("Speed"))
         , " 四元素:" + str(deviceModel.getDeviceData("q1")) + "," + str(deviceModel.getDeviceData("q2")) + "," + str(deviceModel.getDeviceData("q3"))+ "," + str(deviceModel.getDeviceData("q4"))
          )
    if (_IsWriteF):    #记录数据
        Tempstr = " " + str(deviceModel.getDeviceData("Chiptime"))
        Tempstr += "\t"+str(deviceModel.getDeviceData("accX")) + "\t"+str(deviceModel.getDeviceData("accY"))+"\t"+ str(deviceModel.getDeviceData("accZ"))
        Tempstr += "\t" + str(deviceModel.getDeviceData("gyroX")) +"\t"+ str(deviceModel.getDeviceData("gyroY")) +"\t"+ str(deviceModel.getDeviceData("gyroZ"))
        Tempstr += "\t" + str(deviceModel.getDeviceData("angleX")) +"\t" + str(deviceModel.getDeviceData("angleY")) +"\t"+ str(deviceModel.getDeviceData("angleZ"))
        Tempstr += "\t" + str(deviceModel.getDeviceData("temperature"))
        Tempstr += "\t" + str(deviceModel.getDeviceData("magX")) +"\t" + str(deviceModel.getDeviceData("magY")) +"\t"+ str(deviceModel.getDeviceData("magZ"))
        Tempstr += "\t" + str(deviceModel.getDeviceData("lon")) + "\t" + str(deviceModel.getDeviceData("lat"))
        Tempstr += "\t" + str(deviceModel.getDeviceData("Yaw")) + "\t" + str(deviceModel.getDeviceData("Speed"))
        Tempstr += "\t" + str(deviceModel.getDeviceData("q1")) + "\t" + str(deviceModel.getDeviceData("q2"))
        Tempstr += "\t" + str(deviceModel.getDeviceData("q3")) + "\t" + str(deviceModel.getDeviceData("q4"))
        Tempstr += "\r\n"
        _writeF.write(Tempstr)

def startRecord():
    """
    开始记录数据
    :return:
    """
    global _writeF
    global _IsWriteF
    _writeF = open(str(datetime.datetime.now().strftime('%Y%m%d%H%M%S')) + ".txt", "w")    #新建一个文件
    _IsWriteF = True                                                                        #标记写入标识
    Tempstr = "Chiptime"
    Tempstr +=  "\tax(g)\tay(g)\taz(g)"
    Tempstr += "\twx(deg/s)\twy(deg/s)\twz(deg/s)"
    Tempstr += "\tAngleX(deg)\tAngleY(deg)\tAngleZ(deg)"
    Tempstr += "\tT(°)"
    Tempstr += "\tmagx\tmagy\tmagz"
    Tempstr += "\tlon\tlat"
    Tempstr += "\tYaw\tSpeed"
    Tempstr += "\tq1\tq2\tq3\tq4"
    Tempstr += "\r\n"
    _writeF.write(Tempstr)
    print("开始记录数据")

def endRecord():
    """
    结束记录数据
    :return:
    """
    global _writeF
    global _IsWriteF
    _IsWriteF = False             # 标记不可写入标识
    _writeF.close()               #关闭文件
    print("结束记录数据")

if __name__ == '__main__':
    device = deviceModel.DeviceModel(
        "我的JY901",
        WitProtocolResolver(),
        JY901SDataProcessor(),
        "51_0"
    )

    device.serialConfig.portName = "/dev/ttyUSB1"   #设置串口
    device.serialConfig.baud = 9600                     #设置波特率
    device.openDevice()                                 #打开串口
    while 1:
        onUpdate(device)

    device.closeDevice()
    endRecord()                                         #结束记录数据