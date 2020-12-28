import os, subprocess
import threading
import time
from jupiterutils import *
import logging
import psutil

logging.basicConfig(level=logging.DEBUG,
                    format='(%(threadName)-9s) %(message)s',)

def CheckProcessDCAD(procName):
    for proc in psutil.process_iter():
        if proc.name() == procName:
            return True
    return False

def open_Jupiter(e, t):
    path = r"C:\Program Files\TechnoStar\Jupiter-Pre_5.0\Start_It.bat"
    # os.chdir(path)
    # os.system("Start_It.bat")
    subprocess.run(path, shell=True)

    isDCADOpen = False
    while isDCADOpen == False:
        isDCADOpen = CheckProcessDCAD('DCAD_main.exe')
        logging.debug('Is Jupiter running now? %s', isDCADOpen)
    
    wait_time = 20
    logging.debug('Wait for %s seconds', wait_time)
    time.sleep(wait_time)
    logging.debug('$%s seconds passed', wait_time)
    e.set()
    logging.debug('Event set: %s', e.isSet())
    e.clear()

    while not e.isSet():
        event_is_set = e.wait(t)
        logging.debug('event set: %s', event_is_set)
        if event_is_set:
            logging.debug('Quitting Jupiter')
            JPT.QuitApplication()
        else:
            logging.debug('doing other things')
    

def create_Cube(e):
    e.wait()
    logging.debug('Using Jupiter')
    logging.debug('Create Cube')
    Geometry.Part.Cube()
    logging.debug('Fit Model')
    JPT.ViewFitToModel()
    JPT.ClearLog()
    e.set()
    
e = threading.Event()
t1 = threading.Thread(name='open_Jupiter', target=open_Jupiter, args=(e, 2)) 
t2 = threading.Thread(name='create_Cube', target=create_Cube, args=(e,)) 
t1.start()
t2.start()

i = 0
while True:
    time.sleep(1)
    i += 1
    logging.debug('Hello! %s times', i)