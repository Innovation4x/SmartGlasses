import serial
import time
import os

# make sure the 'COM#' is set according the Windows Device Manager
ser = serial.Serial('COM5', 9700, timeout=1)
time.sleep(2)

for i in range(50):
    line = ser.readline()   # read a byte
    if line:
        string = line.decode()  # convert the byte string to a unicode string
        num = int(string) # convert the unicode string to an int
        # os.system('espeak "{}"'.format(num))

        if (num < 20):
            a="StopStop, Close object in front."
            os.system('espeak "{}"'.format(a))

        elif (20 < num < 60):
            b="object is quite a distance away."
            os.system('espeak "{}"'.format(b))

        elif (40 < num < 100):

            c="object is 1 meter away."
            os.system('espeak "{}"'.format(c))

        else:
            d="Object is far away."
            os.system('espeak "{}"'.format(d))

ser.close()