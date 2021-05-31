# -*- coding: utf-8 -*-
"""
Open the file with Terminal: 
python weather.py -r "Region"

e.g. python weather.py -r "Tai Po"

"""

import requests
import pandas as pd
import json
import sys, getopt
import unittest

dUpdate=""
gWeather=pd.DataFrame({'A' : []})
#%%
def getData():
    global dUpdate,gWeather
    url="https://data.weather.gov.hk/weatherAPI/opendata/weather.php?dataType=rhrread&lang=en"
    response = requests.get(url)
    data = response.text
    jdata = json.loads(data)
    dTemp=jdata['temperature']['data']
    dRain=jdata['rainfall']['data']
    dUpdate=jdata['updateTime']
    
    dfTemp=pd.DataFrame(dTemp)
    dfRain=pd.DataFrame(dRain)
    
### Your code
### Q1
###   
    dfRain=dfRain.set_index('place')
    dfTemp=dfTemp.set_index('place')
    gWeather = pd.concat([dfRain, dfTemp], axis=1, join='outer') # Outer join
    return gWeather
   
#%%
def getDateTime(sDateTime):
    sDate=sDateTime.split("T")[0]
    sTime=sDateTime.split("T")[1].split("+")[0]
    return sDate,sTime
#%%
def getTempRain(Region,weather):
    nTemp = -1
    nRain = -1
    
### Your Code
### Q2
###
    
    if Region in weather.index:
        if (str(weather.loc[Region]['value']) != 'nan'):
            nTemp = weather.loc[Region]['value']
        if (str(weather.loc[Region]['max']) != 'nan'):
            nRain = weather.loc[Region]['max']

    return nTemp, nRain      

#%%
def Report(Place,cTemp, cRain,cDate,cTime):
    if (cTemp == -1 and cRain == -1):
        print(f"No record for {Place}")
    else:
        print("-----------------------------------------------")
        print("Current Weather Summary on {} at {}".format(cDate,cTime))
        print("Location: {}".format(Place))
        if (cTemp != -1):
             print("Current  Temperature: {:.1f} C".format(cTemp))
        if (cRain != -1):
            if (cRain < 0.05):
                print("No rainfall for the last hour")
            else:
                print("Rainfall for the last hour: {:.1f} mm".format(cRain))
        print("----------------End of Report-----------------")
 
### Your code
### Q3
### 
#%%       
mHELP = 'weather.py -r Region'

def main(argv):
    try:
        opts, args = getopt.getopt(argv,"r:")
    except getopt.GetoptError:
        print (mHELP)
        sys.exit(2)    
    for opt, arg in opts:
        if opt == '-r':
            sDate,sTime=getDateTime(dUpdate)
            nTemp,nRain=getTempRain(arg,gWeather)
### Your Code
### Q4
###  
            print(Report(arg, nTemp, nRain, sDate, sTime))
            sys.exit()
    print(mHELP)            
            
#    LastReport()
if (__name__ == "__main__"):
    weather = getData()
    main(sys.argv[1:])

       
else:
##  Unit Test for Q1, Q2 and Q3    
    print("Testing")
    weather = getData()
    


class Test(unittest.TestCase):

    def test_getData(self):
        self.assertEqual(weather)

    def test_getTempRain(self):
        self.assertEqual(getTempRain("Tai Po", weather))
        
    def test_Report(self):
        self.assertEqual(Report("Tai Po", 25, 0.325, "2020-04-02", "21:00"))
        
if __name__ == '__main__':
    unittest.main()
  
   

    
    
