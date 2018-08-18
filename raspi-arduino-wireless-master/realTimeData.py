import os
import time
import sys
from pubnub import Pubnub
import Adafruit_DHT as dht

pubnub = Pubnub( publish_key = 'pub-c-3cfe4559-c152-42d9-9185-710fe1215e65',
    subscribe_key = 'sub-c-828e2f18-4106-11e6-bfbb-02ee2ddab7fe')

# name : MD Hasib, MD_hz1994

channel = 'tempeon'
#channel = 'humeon'


def callback(message):
    print(message)


while True:

    h,t = dht.read_retry(dht.DHT11,4)
    print 'Temp = {0:0.1f}*C Humidity = {1:0.1f}%'.format(t,h)
    pubnub.publish('tempeon' , {
        'columns': [
            ['x',time.time()],
            ['temperature_celcius',t]
            ]

        })
    pubnub.publish('humeon' , {
        'columns': [
            ['humidity',h]
            ]

        })
   
