EESchema Schematic File Version 4
LIBS:RPi_GPIO-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L RPi_Hat-rescue:RPi_GPIO J2
U 1 1 5516AE26
P 8950 850
AR Path="/5516AE26" Ref="J2"  Part="1" 
AR Path="/5515D395/5516AE26" Ref="J2"  Part="1" 
F 0 "J2" H 9700 1100 60  0000 C CNN
F 1 "RPi_GPIO" H 9700 1000 60  0000 C CNN
F 2 "PiHat:Pin_Header_Straight_2x20" H 8950 850 60  0001 C CNN
F 3 "" H 8950 850 60  0000 C CNN
	1    8950 850 
	1    0    0    -1  
$EndComp
Text Notes 7800 5000 0    60   Italic 0
Thru-Hole Connector
$Comp
L Driver_Motor:Pololu_Breakout_A4988 SMC1
U 1 1 5C782821
P 4000 3000
F 0 "SMC1" H 4050 3878 50  0000 C CNN
F 1 "Pololu_Breakout_A4988" H 4050 3787 50  0000 C CNN
F 2 "Module:Pololu_Breakout-16_15.2x20.3mm" H 4275 2250 50  0001 L CNN
F 3 "https://www.pololu.com/product/2980/pictures" H 4100 2700 50  0001 C CNN
	1    4000 3000
	1    0    0    -1  
$EndComp
$Comp
L Driver_Motor:Pololu_Breakout_A4988 SMC2
U 1 1 5C7828D9
P 4050 4750
F 0 "SMC2" H 4100 5628 50  0000 C CNN
F 1 "Pololu_Breakout_A4988" H 4100 5537 50  0000 C CNN
F 2 "Module:Pololu_Breakout-16_15.2x20.3mm" H 4325 4000 50  0001 L CNN
F 3 "https://www.pololu.com/product/2980/pictures" H 4150 4450 50  0001 C CNN
	1    4050 4750
	1    0    0    -1  
$EndComp
$Comp
L pspice:CAP 12VCap1
U 1 1 5C782DDC
P 2250 2100
F 0 "12VCap1" H 2428 2146 50  0000 L CNN
F 1 "CAP" H 2428 2055 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L9.0mm_W6.7mm_P7.50mm_MKT" H 2250 2100 50  0001 C CNN
F 3 "~" H 2250 2100 50  0001 C CNN
	1    2250 2100
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 5VCon1
U 1 1 5C782FA6
P 1550 1500
F 0 "5VCon1" H 1470 1175 50  0000 C CNN
F 1 "Screw_Terminal_01x02" H 1470 1266 50  0000 C CNN
F 2 "TerminalBlock:TerminalBlock_bornier-2_P5.08mm" H 1550 1500 50  0001 C CNN
F 3 "~" H 1550 1500 50  0001 C CNN
	1    1550 1500
	-1   0    0    1   
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 12VCon1
U 1 1 5C7830BE
P 1550 2150
F 0 "12VCon1" H 1470 1825 50  0000 C CNN
F 1 "Screw_Terminal_01x02" H 1470 1916 50  0000 C CNN
F 2 "TerminalBlock:TerminalBlock_bornier-2_P5.08mm" H 1550 2150 50  0001 C CNN
F 3 "~" H 1550 2150 50  0001 C CNN
	1    1550 2150
	-1   0    0    1   
$EndComp
Wire Wire Line
	1750 2050 2000 2050
Wire Wire Line
	2000 2050 2000 1850
Wire Wire Line
	2000 1850 2250 1850
Wire Wire Line
	1750 2150 1750 2350
Wire Wire Line
	1750 2350 2250 2350
$Comp
L Connector:Conn_01x04_Male SM1
U 1 1 5C7833AB
P 5100 3100
F 0 "SM1" H 5073 2980 50  0000 R CNN
F 1 "Conn_01x04_Male" H 5073 3071 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 5100 3100 50  0001 C CNN
F 3 "~" H 5100 3100 50  0001 C CNN
	1    5100 3100
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x04_Male SM2
U 1 1 5C783735
P 5050 4850
F 0 "SM2" H 5023 4730 50  0000 R CNN
F 1 "Conn_01x04_Male" H 5023 4821 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 5050 4850 50  0001 C CNN
F 3 "~" H 5050 4850 50  0001 C CNN
	1    5050 4850
	-1   0    0    1   
$EndComp
Wire Wire Line
	1750 1500 1750 1800
Wire Wire Line
	1750 1800 650  1800
Wire Wire Line
	650  1800 650  2350
Wire Wire Line
	650  2350 1750 2350
Connection ~ 1750 2350
Text Label 1200 1800 0    50   ~ 0
GND
Text Label 2050 1850 0    50   ~ 0
12V
Wire Wire Line
	1750 2350 1750 3800
Wire Wire Line
	1750 3800 3000 3800
Wire Wire Line
	4000 3800 4200 3800
Connection ~ 4000 3800
Wire Wire Line
	3450 3800 3450 5550
Connection ~ 3450 3800
Wire Wire Line
	3450 3800 4000 3800
Connection ~ 4200 3800
Wire Wire Line
	1750 1400 3200 1400
Wire Wire Line
	4700 1400 4700 550 
Wire Wire Line
	4700 550  10800 550 
Wire Wire Line
	10800 550  10800 850 
Wire Wire Line
	10800 850  10650 850 
Text Label 3800 1400 0    50   ~ 0
5V
Wire Wire Line
	7300 2750 8750 2750
Wire Wire Line
	4850 4950 4650 4950
Wire Wire Line
	4900 3200 4500 3200
Wire Wire Line
	4900 3100 4500 3100
Wire Wire Line
	4900 3000 4500 3000
Wire Wire Line
	4900 2900 4500 2900
$Comp
L Connector:Conn_01x03_Male S1
U 1 1 5C78B611
P 2300 4600
F 0 "S1" H 2406 4878 50  0000 C CNN
F 1 "Conn_01x03_Male" H 2406 4787 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 2300 4600 50  0001 C CNN
F 3 "~" H 2300 4600 50  0001 C CNN
	1    2300 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2500 4600 3200 4600
Wire Wire Line
	3200 4600 3200 1400
Connection ~ 3200 1400
Wire Wire Line
	3200 1400 3300 1400
Wire Wire Line
	2500 4700 3000 4700
Wire Wire Line
	3000 4700 3000 3800
Connection ~ 3000 3800
Wire Wire Line
	3000 3800 3450 3800
Wire Wire Line
	2500 4500 2800 4500
Wire Wire Line
	2800 4500 2800 7550
Wire Wire Line
	2800 7550 6750 7550
Wire Wire Line
	6750 7550 6750 6400
Wire Wire Line
	4050 4050 3300 4050
Wire Wire Line
	3300 4050 3300 2300
Connection ~ 3300 1400
Wire Wire Line
	3300 1400 4700 1400
Wire Wire Line
	3300 2300 4000 2300
Connection ~ 3300 2300
Wire Wire Line
	3300 2300 3300 1400
Wire Wire Line
	2250 1850 4200 1850
Wire Wire Line
	4200 1850 4200 2300
Connection ~ 2250 1850
Wire Wire Line
	4200 1850 5800 1850
Wire Wire Line
	5800 1850 5800 4050
Wire Wire Line
	5800 4050 4250 4050
Connection ~ 4200 1850
Wire Wire Line
	3650 4350 3600 4350
Wire Wire Line
	3600 4350 3600 4450
Wire Wire Line
	3600 4450 3650 4450
Wire Wire Line
	3600 2600 3550 2600
Wire Wire Line
	3550 2600 3550 2700
Wire Wire Line
	3550 2700 3600 2700
Wire Wire Line
	3600 3100 3400 3100
Wire Wire Line
	3400 3100 3400 2000
Wire Wire Line
	3400 2000 7900 2000
Wire Wire Line
	7900 2000 7900 3650
Wire Wire Line
	3600 3000 3500 3000
Wire Wire Line
	3500 3000 3500 2100
Wire Wire Line
	3500 2100 7800 2100
Wire Wire Line
	7800 2100 7800 3900
Wire Wire Line
	3600 5650 3600 4850
Wire Wire Line
	3600 4850 3650 4850
Wire Wire Line
	3650 4750 3550 4750
Wire Wire Line
	3550 4750 3550 5700
$Comp
L Connector:Conn_01x04_Male SM3
U 1 1 5C7AD885
P 5050 5250
F 0 "SM3" H 5023 5130 50  0000 R CNN
F 1 "Conn_01x04_Male" H 5023 5221 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 5050 5250 50  0001 C CNN
F 3 "~" H 5050 5250 50  0001 C CNN
	1    5050 5250
	-1   0    0    1   
$EndComp
Wire Wire Line
	4550 4850 4700 4850
Wire Wire Line
	3450 5550 4050 5550
Wire Wire Line
	4250 5550 4050 5550
Connection ~ 4050 5550
Wire Wire Line
	4550 4650 4800 4650
Wire Wire Line
	4550 4750 4750 4750
Wire Wire Line
	4800 4650 4800 5050
Wire Wire Line
	4800 5050 4850 5050
Connection ~ 4800 4650
Wire Wire Line
	4800 4650 4850 4650
Wire Wire Line
	4750 4750 4750 5150
Wire Wire Line
	4750 5150 4850 5150
Connection ~ 4750 4750
Wire Wire Line
	4750 4750 4850 4750
Wire Wire Line
	4700 4850 4700 5250
Wire Wire Line
	4700 5250 4850 5250
Connection ~ 4700 4850
Wire Wire Line
	4700 4850 4850 4850
Wire Wire Line
	4650 4950 4650 5350
Wire Wire Line
	4650 5350 4850 5350
Connection ~ 4650 4950
Wire Wire Line
	4650 4950 4550 4950
$Comp
L MCU_Module:Arduino_Nano_v3.x A?
U 1 1 5C80A084
P 8050 5200
F 0 "A?" H 8050 4114 50  0000 C CNN
F 1 "Arduino_Nano_v3.x" H 8050 4023 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 8200 4250 50  0001 L CNN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 8050 4200 50  0001 C CNN
	1    8050 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6750 6400 7300 6400
Wire Wire Line
	7300 6400 7300 4900
Wire Wire Line
	7300 4900 7550 4900
Wire Wire Line
	3550 5700 7550 5700
Wire Wire Line
	7250 5650 7250 5800
Wire Wire Line
	7250 5800 7550 5800
Wire Wire Line
	3600 5650 7250 5650
Wire Wire Line
	7800 3900 7450 3900
Wire Wire Line
	7450 3900 7450 5500
Wire Wire Line
	7450 5500 7550 5500
Wire Wire Line
	7900 3650 7500 3650
Wire Wire Line
	7500 3650 7500 5400
Wire Wire Line
	7500 5400 7550 5400
Wire Wire Line
	7300 2750 7300 3800
Wire Wire Line
	4200 3800 7300 3800
$Comp
L Connector:Conn_01x04_Male MMC
U 1 1 5C83F9B6
P 9800 3200
F 0 "MMC" H 9906 3478 50  0000 C CNN
F 1 "Conn_01x04_Male" H 9906 3387 50  0000 C CNN
F 2 "Connector:NS-Tech_Grove_1x04_P2mm_Vertical" H 9800 3200 50  0001 C CNN
F 3 "~" H 9800 3200 50  0001 C CNN
	1    9800 3200
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x05_Male ENC1
U 1 1 5C84907A
P 9800 3850
F 0 "ENC1" H 9773 3780 50  0000 R CNN
F 1 "Conn_01x05_Male" H 9773 3871 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 9800 3850 50  0001 C CNN
F 3 "~" H 9800 3850 50  0001 C CNN
	1    9800 3850
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x05_Male ENC2
U 1 1 5C8526DD
P 9800 4450
F 0 "ENC2" H 9773 4380 50  0000 R CNN
F 1 "Conn_01x05_Male" H 9773 4471 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 9800 4450 50  0001 C CNN
F 3 "~" H 9800 4450 50  0001 C CNN
	1    9800 4450
	-1   0    0    1   
$EndComp
$EndSCHEMATC
