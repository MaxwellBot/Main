import pygame as p
from pygame.locals import *
import time
from time import *
import os, random
import numpy as np
import scipy.io.wavfile


p.init()
screen=p.display.set_mode((320,320), 0, 32)

BL  = (0,0,0)
W  = (255,255,255)
R    = (255,0,0)
G  = (0,255,0)
B   = (0,0,255)
Y = (255,255,0)


def pixel(color,x,y,w,h):
    p.draw.rect(screen, color, (x*10-9,y*10-9,w*10,h*10),0)

    #all lefts and rights are from viewers perspective
def lbrw(upvalue):#-------------------left eyebrow
    pixel(B, 8, 6-upvalue, 7, 1)
def rbrw(upvalue):#-------------------right eyebrow
    pixel(B,19, 6-upvalue, 7, 1)
def leye(ud,lr):#-------------------left eye
    pixel(B,10+lr, 8+ud, 4, 1)
    pixel(B, 9+lr, 9+ud, 1, 1)
    pixel(B,14+lr, 9+ud, 1, 1)
    pixel(B,8+lr, 10+ud, 1, 4)
    pixel(B,15+lr,10+ud, 1, 4)
    pixel(B,11+lr,11+ud, 2, 2)
    pixel(B, 9+lr,14+ud, 6, 1)
def reye(ud,lr):#-------------------right eye
    pixel(B,20+lr, 8+ud, 4, 1)
    pixel(B,19+lr, 9+ud, 1, 1)
    pixel(B,24+lr, 9+ud, 1, 1)
    pixel(B,18+lr,10+ud, 1, 4)
    pixel(B,25+lr,10+ud, 1, 4)
    pixel(B,21+lr,11+ud, 2, 2)
    pixel(B,19+lr,14+ud, 6, 1)
def mout(state):#-------------------mouth
    pixel(B, 9,23,16, 1)
    pixel(B, 9+state,23+state, 1, 1)
    pixel(B,24-state,23+state, 1, 1)
    pixel(B, 9+(0 if (state-1) < 0 else (state-1)),23+(0 if (state-1) < 0 else (state-1)), 1, 1)
    pixel(B,24-(0 if (state-1) < 0 else (state-1)),23+(0 if (state-1) < 0 else (state-1)), 1, 1)
    pixel(B, 9+(0 if (state-2) < 0 else (state-2)),23+(0 if (state-2) < 0 else (state-2)), 1, 1)
    pixel(B,24-(0 if (state-2) < 0 else (state-2)),23+(0 if (state-2) < 0 else (state-2)), 1, 1)
    pixel(B,10+state,24+state, 14-(2*state), 1)
    
 #==============================updating face: highest level   
def updateface(lb,rb,ud,lr,m):
    pixel(BL,1,1,32,32)
    if ud==-1:
        lb=1
        rb=1
    #0 for normal, 1 for raised
    lbrw(lb)
    rbrw(rb)
    # ud/lr (-1 is up/left)
    leye(ud,lr)
    reye(ud,lr)
    #mout expects 0-3
    mout(m)
    p.display.update()
while 1==1:
    updateface(0,0,0,0,0)
    rate, data = scipy.io.wavfile.read('wavs/Greeting-1.wav')
    sin_data = np.sin(data)
    i=0
    amp=0
    while i<len(data):
        if   abs(data[i][0]) >=0     and abs(data[i][0]) < 400 :
            m=0
        elif abs(data[i][0]) >=400  and abs(data[i][0]) < 5000:
            m=1
        elif abs(data[i][0]) >=5000 and abs(data[i][0]) < 8000:
            m=2
        else:
            m=3
        updateface(0,0,0,0,m)
        i=i+1000
        sleep(.018)
    while 1==1:
        sleep(1)






