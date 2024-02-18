EESchema Schematic File Version 4
EELAYER 30 0
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
L Device:C C2
U 1 1 6089FD74
P 1730 3680
F 0 "C2" V 1478 3680 50  0000 C CNN
F 1 "100nF" V 1569 3680 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D10.0mm_W2.5mm_P5.00mm" H 1768 3530 50  0001 C CNN
F 3 "~" H 1730 3680 50  0001 C CNN
	1    1730 3680
	0    1    1    0   
$EndComp
$Comp
L Device:C C1
U 1 1 608A226D
P 1780 2860
F 0 "C1" V 1528 2860 50  0000 C CNN
F 1 "100nF" V 1619 2860 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D10.0mm_W2.5mm_P5.00mm" H 1818 2710 50  0001 C CNN
F 3 "~" H 1780 2860 50  0001 C CNN
	1    1780 2860
	0    1    1    0   
$EndComp
Wire Wire Line
	1580 3680 1480 3680
Text Label 3450 2050 1    50   ~ 0
RST
Text Label 2120 3600 0    50   ~ 0
VDD
Text Label 1480 3680 0    50   ~ 0
VSS
Wire Wire Line
	4350 1750 4450 1750
Text Label 4450 1750 0    50   ~ 0
VDD
$Comp
L Connector:Conn_01x05_Female J6
U 1 1 608B748C
P 8750 2270
F 0 "J6" H 8778 2296 50  0000 L CNN
F 1 "Conn_01x05_Female" H 8778 2205 50  0000 L CNN
F 2 "p4:PinHeader_1x05_P2.54mm_Vertical" H 8750 2270 50  0001 C CNN
F 3 "~" H 8750 2270 50  0001 C CNN
	1    8750 2270
	1    0    0    -1  
$EndComp
Text Label 8550 2070 2    50   ~ 0
RST
Text Label 8550 2270 2    50   ~ 0
VDD
Text Label 8550 2170 2    50   ~ 0
VSS
Text Label 5250 3450 0    50   ~ 0
PGD
Text Label 5250 3350 0    50   ~ 0
PGC
$Comp
L CONECTORES:P4Femea CNP1
U 1 1 608BB0B2
P 1630 1780
F 0 "CNP1" H 1688 2095 50  0000 C CNN
F 1 "P4Femea" H 1688 2004 50  0000 C CNN
F 2 "p4:ConnP4" H 1780 1680 50  0000 C CNN
F 3 "" H 1780 1680 50  0001 C CNN
	1    1630 1780
	1    0    0    -1  
$EndComp
Text Label 8550 2470 2    50   ~ 0
PGD
Text Label 8550 2370 2    50   ~ 0
PGC
$Comp
L Device:C C3
U 1 1 608BD8C9
P 2740 2150
F 0 "C3" V 2488 2150 50  0000 C CNN
F 1 "22pF" V 2579 2150 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D10.0mm_W2.5mm_P5.00mm" H 2778 2000 50  0001 C CNN
F 3 "~" H 2740 2150 50  0001 C CNN
	1    2740 2150
	0    1    1    0   
$EndComp
$Comp
L Device:Crystal Y1
U 1 1 608BE978
P 2900 2380
F 0 "Y1" V 2854 2511 50  0000 L CNN
F 1 "20MHz" V 2945 2511 50  0000 L CNN
F 2 "Crystal:Crystal_HC49-4H_Vertical" H 2900 2380 50  0001 C CNN
F 3 "~" H 2900 2380 50  0001 C CNN
	1    2900 2380
	0    1    1    0   
$EndComp
Wire Wire Line
	2900 2230 2900 2150
Wire Wire Line
	2900 2150 2890 2150
Wire Wire Line
	2900 2610 2900 2530
$Comp
L Device:R R1
U 1 1 608C1DF7
P 1660 4300
F 0 "R1" V 1453 4300 50  0000 C CNN
F 1 "1K" V 1544 4300 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1590 4300 50  0001 C CNN
F 3 "~" H 1660 4300 50  0001 C CNN
	1    1660 4300
	0    1    1    0   
$EndComp
$Comp
L Device:LED D1
U 1 1 608C212F
P 1960 4300
F 0 "D1" H 1953 4517 50  0000 C CNN
F 1 "LED" H 1953 4426 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 1960 4300 50  0001 C CNN
F 3 "~" H 1960 4300 50  0001 C CNN
	1    1960 4300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 608CB005
P 3260 1360
F 0 "R3" H 3190 1314 50  0000 R CNN
F 1 "10K" H 3190 1405 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 3190 1360 50  0001 C CNN
F 3 "~" H 3260 1360 50  0001 C CNN
	1    3260 1360
	-1   0    0    1   
$EndComp
Wire Wire Line
	3260 2050 3260 1820
Wire Wire Line
	3010 1820 3260 1820
Connection ~ 3260 1820
Wire Wire Line
	3260 1820 3260 1510
Text Label 2610 1820 2    50   ~ 0
VSS
Text Label 3260 1210 0    50   ~ 0
VDD
Wire Wire Line
	4350 4650 4450 4650
Text Label 4400 4650 3    50   ~ 0
VSS
Wire Wire Line
	5240 4250 5250 4250
Wire Wire Line
	3450 2740 3450 2750
Wire Wire Line
	3450 2840 3450 2850
Wire Wire Line
	3450 2940 3450 2950
Wire Wire Line
	3450 3040 3450 3050
Wire Wire Line
	3450 3140 3450 3150
Wire Wire Line
	3450 3240 3450 3250
Wire Wire Line
	3450 3340 3450 3350
Wire Wire Line
	3450 3440 3450 3450
$Comp
L Device:LED D2
U 1 1 60924EE5
P 3090 3860
F 0 "D2" H 3083 4077 50  0000 C CNN
F 1 "LED" H 3083 3986 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 3090 3860 50  0001 C CNN
F 3 "~" H 3090 3860 50  0001 C CNN
	1    3090 3860
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 60925B92
P 2690 3860
F 0 "R2" V 2483 3860 50  0000 C CNN
F 1 "1K" V 2574 3860 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 2620 3860 50  0001 C CNN
F 3 "~" H 2690 3860 50  0001 C CNN
	1    2690 3860
	0    1    1    0   
$EndComp
Wire Wire Line
	2840 3860 2940 3860
Text Label 2540 3860 1    50   ~ 0
VSS
$Comp
L MCU_Microchip_PIC16:PIC16F877A-IP U2
U 1 1 608A4A74
P 4350 3150
F 0 "U2" H 4350 4731 50  0000 C CNN
F 1 "PIC16F877A-IP" H 4350 4640 50  0000 C CNN
F 2 "Package_DIP:DIP-40_W15.24mm_LongPads" H 4350 3150 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/39582b.pdf" H 4350 3150 50  0001 C CNN
	1    4350 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1480 3680 1480 3930
Connection ~ 1480 3680
$Comp
L Connector:Conn_01x08_Female J4
U 1 1 608CF5D8
P 6880 2950
F 0 "J4" H 6908 2926 50  0000 L CNN
F 1 "Conn_01x08_Female" H 6908 2835 50  0000 L CNN
F 2 "p4:PinHeader_1x07_P2.54mm_Vertical" H 6880 2950 50  0001 C CNN
F 3 "~" H 6880 2950 50  0001 C CNN
	1    6880 2950
	1    0    0    -1  
$EndComp
Text Label 6680 2750 2    50   ~ 0
RC0
Text Label 6680 2850 2    50   ~ 0
RC1
Text Label 6680 2950 2    50   ~ 0
RC2
Text Label 6680 3050 2    50   ~ 0
RC3
Text Label 6680 3150 2    50   ~ 0
RD0
Text Label 6680 3250 2    50   ~ 0
RD1
Wire Wire Line
	5250 2020 5250 2050
Wire Wire Line
	5250 2020 5270 2020
Wire Wire Line
	5250 2120 5250 2150
Text Label 3450 2750 2    50   ~ 0
RD0
Text Label 3450 2850 2    50   ~ 0
RD1
Text Label 5250 3650 0    50   ~ 0
RC0
Text Label 5250 3750 0    50   ~ 0
RC1
Text Label 5250 3850 0    50   ~ 0
RC2
Text Label 5250 3950 0    50   ~ 0
RC3
Text Label 3450 3650 2    50   ~ 0
RE0
Text Label 3450 3750 2    50   ~ 0
RE1
$Comp
L Connector:Conn_01x18_Female J1
U 1 1 60909E7D
P 6880 4350
F 0 "J1" H 6908 4326 50  0000 L CNN
F 1 "Conn_01x18_Female" H 6908 4235 50  0000 L CNN
F 2 "p4:PinHeader_1x18_P2.54mm_Vertical" H 6880 4350 50  0001 C CNN
F 3 "~" H 6880 4350 50  0001 C CNN
	1    6880 4350
	1    0    0    -1  
$EndComp
Text Label 6680 3550 2    50   ~ 0
RB7
Text Label 6680 3650 2    50   ~ 0
RB6
Text Label 6680 3750 2    50   ~ 0
RB5
Text Label 6680 3850 2    50   ~ 0
RB4
Text Label 6680 3950 2    50   ~ 0
RB3
Text Label 6680 4050 2    50   ~ 0
RB2
Text Label 6680 4150 2    50   ~ 0
RB1
Text Label 6680 4250 2    50   ~ 0
RB0
Text Label 6680 4350 2    50   ~ 0
RD7
Text Label 6680 4450 2    50   ~ 0
RD6
Text Label 6680 4550 2    50   ~ 0
RD5
Text Label 6680 4650 2    50   ~ 0
RD4
Text Label 6680 4750 2    50   ~ 0
RC7
Text Label 6680 4850 2    50   ~ 0
RC6
Text Label 6680 4950 2    50   ~ 0
RC5
Text Label 6680 5050 2    50   ~ 0
RC4
Text Label 6680 5150 2    50   ~ 0
RD3
Text Label 6680 5250 2    50   ~ 0
RD2
Text Label 3450 2950 2    50   ~ 0
RD2
Text Label 3450 3050 2    50   ~ 0
RD3
Text Label 3450 3150 2    50   ~ 0
RD4
Text Label 3450 3350 2    50   ~ 0
RD6
Text Label 3450 3250 2    50   ~ 0
RD5
Text Label 3450 3450 2    50   ~ 0
RD7
Text Label 5250 2450 0    50   ~ 0
RA4
Text Label 5250 2550 0    50   ~ 0
RA5
Text Label 5250 2750 0    50   ~ 0
RB0
Text Label 5250 2850 0    50   ~ 0
RB1
Text Label 5250 2950 0    50   ~ 0
RB2
Text Label 5250 3050 0    50   ~ 0
RB3
Text Label 5250 3150 0    50   ~ 0
RB4
Text Label 5250 3250 0    50   ~ 0
RB5
Text Label 5250 3350 2    50   ~ 0
RB6
Text Label 5250 3450 2    50   ~ 0
RB7
Text Label 5250 4050 0    50   ~ 0
RC4
Text Label 5250 4150 0    50   ~ 0
RC5
Text Label 5250 4250 0    50   ~ 0
RC6
Text Label 5250 4350 0    50   ~ 0
RC7
$Comp
L Device:C C4
U 1 1 609129E4
P 2740 2610
F 0 "C4" V 2488 2610 50  0000 C CNN
F 1 "22pF" V 2579 2610 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D10.0mm_W2.5mm_P5.00mm" H 2778 2460 50  0001 C CNN
F 3 "~" H 2740 2610 50  0001 C CNN
	1    2740 2610
	0    1    1    0   
$EndComp
Wire Wire Line
	2890 2610 2900 2610
Wire Wire Line
	3240 3860 3390 3860
Wire Wire Line
	3390 3860 3390 3850
Wire Wire Line
	3390 3850 3450 3850
Text Label 2590 2150 2    50   ~ 0
VSS
Text Label 2590 2610 2    50   ~ 0
VSS
Wire Wire Line
	2900 2150 3450 2150
Wire Wire Line
	3450 2150 3450 2350
Connection ~ 2900 2150
Wire Wire Line
	3450 2610 3450 2550
Wire Wire Line
	2900 2610 3450 2610
Connection ~ 2900 2610
$Comp
L Switch:SW_Push SW1
U 1 1 608C6650
P 2810 1820
F 0 "SW1" H 2810 2105 50  0000 C CNN
F 1 "SW_Push" H 2810 2014 50  0000 C CNN
F 2 "Button_Switch_THT:SW_DIP_SPSTx01_Slide_9.78x4.72mm_W7.62mm_P2.54mm" H 2810 2020 50  0001 C CNN
F 3 "~" H 2810 2020 50  0001 C CNN
	1    2810 1820
	1    0    0    -1  
$EndComp
Wire Wire Line
	3260 2050 3460 2050
$Comp
L Device:CP C5
U 1 1 60B84A05
P 1730 3930
F 0 "C5" V 1475 3930 50  0000 C CNN
F 1 "220uF" V 1566 3930 50  0000 C CNN
F 2 "Capacitor_THT:CP_Radial_D10.0mm_P5.00mm" H 1768 3780 50  0001 C CNN
F 3 "~" H 1730 3930 50  0001 C CNN
	1    1730 3930
	0    1    1    0   
$EndComp
$Comp
L Device:CP C6
U 1 1 60B8C782
P 1780 2620
F 0 "C6" V 1525 2620 50  0000 C CNN
F 1 "220uF" V 1616 2620 50  0000 C CNN
F 2 "Capacitor_THT:CP_Radial_D10.0mm_P5.00mm" H 1818 2470 50  0001 C CNN
F 3 "~" H 1780 2620 50  0001 C CNN
	1    1780 2620
	0    1    1    0   
$EndComp
Wire Wire Line
	1580 3930 1480 3930
Connection ~ 1480 3930
$Comp
L pspice:DIODE D3
U 1 1 60BA0058
P 2120 2350
F 0 "D3" V 2074 2478 50  0000 L CNN
F 1 "1N4007" V 2165 2478 50  0000 L CNN
F 2 "Diode_THT:D_DO-15_P10.16mm_Horizontal" H 2120 2350 50  0001 C CNN
F 3 "~" H 2120 2350 50  0001 C CNN
	1    2120 2350
	0    1    1    0   
$EndComp
Text Label 1480 2030 0    50   ~ 0
VSS
Text Label 1980 1780 0    50   ~ 0
VSS
$Comp
L Regulator_Linear:L7805 U1
U 1 1 60BC721A
P 2120 3300
F 0 "U1" V 2074 3405 50  0000 L CNN
F 1 "L7805" V 2165 3405 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 2145 3150 50  0001 L CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/41/4f/b3/b0/12/d4/47/88/CD00000444.pdf/files/CD00000444.pdf/jcr:content/translations/en.CD00000444.pdf" H 2120 3250 50  0001 C CNN
	1    2120 3300
	0    1    1    0   
$EndComp
Wire Wire Line
	1820 3300 1480 3300
Connection ~ 1480 3300
Wire Wire Line
	1480 3300 1480 3680
Wire Wire Line
	2120 2860 2120 3000
Wire Wire Line
	2120 3600 2120 3680
Wire Wire Line
	1880 3680 2120 3680
Connection ~ 2120 3680
Wire Wire Line
	2120 3680 2120 3930
Wire Wire Line
	1880 3930 2120 3930
Connection ~ 2120 3930
Wire Wire Line
	1480 3930 1480 4300
Wire Wire Line
	1480 2030 1480 2620
Wire Wire Line
	1630 2620 1480 2620
Connection ~ 1480 2620
Wire Wire Line
	2120 4300 2110 4300
Wire Wire Line
	2120 3930 2120 4300
Wire Wire Line
	1480 4300 1510 4300
Wire Wire Line
	2120 2030 2120 2150
Wire Wire Line
	2120 2860 2120 2620
Wire Wire Line
	1930 2860 2120 2860
Wire Wire Line
	1930 2620 2120 2620
Connection ~ 2120 2620
Wire Wire Line
	2120 2620 2120 2550
Wire Wire Line
	1480 2620 1480 2860
Wire Wire Line
	1630 2860 1480 2860
Connection ~ 1480 2860
Wire Wire Line
	1480 2860 1480 3300
Wire Wire Line
	1780 2030 2120 2030
$Comp
L Connector:Conn_01x07_Female J2
U 1 1 60B92EC4
P 7140 1960
F 0 "J2" H 7168 1986 50  0000 L CNN
F 1 "Conn_01x07_Female" H 7168 1895 50  0000 L CNN
F 2 "p4:PinHeader_1x07_P2.54mm_Vertical" H 7140 1960 50  0001 C CNN
F 3 "~" H 7140 1960 50  0001 C CNN
	1    7140 1960
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 2120 5350 2120
Wire Wire Line
	6940 1750 6940 1760
Text Label 6940 2060 2    50   ~ 0
RA4
Text Label 6940 2160 2    50   ~ 0
RA5
Text Label 6940 2260 2    50   ~ 0
RE0
Text Label 6680 2650 2    50   ~ 0
RE1
$Comp
L Connector:Conn_01x04_Female J3
U 1 1 60BD345E
P 1810 4970
F 0 "J3" H 1702 4545 50  0000 C CNN
F 1 "Conn_01x04_Female" H 1702 4636 50  0000 C CNN
F 2 "p4:PinHeader_1x04_P2.54mm_Vertical" H 1810 4970 50  0001 C CNN
F 3 "~" H 1810 4970 50  0001 C CNN
	1    1810 4970
	-1   0    0    1   
$EndComp
Text Label 2010 4770 0    50   ~ 0
VSS
Text Label 2010 4870 0    50   ~ 0
VCC
Text Label 2010 4970 0    50   ~ 0
VSS
Text Label 2010 5070 0    50   ~ 0
VDD
Text Label 1780 2030 0    50   ~ 0
VCC
NoConn ~ 6680 3350
Text Label 6940 1660 0    50   ~ 0
RA0
Text Label 6940 1760 0    50   ~ 0
RA1
Text Label 6940 1860 0    50   ~ 0
RA2
Text Label 6940 1960 0    50   ~ 0
RA3
Text Label 5250 2050 0    50   ~ 0
RA0
Text Label 5250 2150 0    50   ~ 0
RA1
Text Label 5250 2250 0    50   ~ 0
RA2
Text Label 5250 2350 0    50   ~ 0
RA3
$Comp
L Transistor_BJT:BC337 Q1
U 1 1 60BF75E6
P 6080 1290
F 0 "Q1" V 6408 1290 50  0000 C CNN
F 1 "BC337" V 6317 1290 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 6280 1215 50  0001 L CIN
F 3 "https://diotec.com/tl_files/diotec/files/pdf/datasheets/bc337.pdf" H 6080 1290 50  0001 L CNN
	1    6080 1290
	0    -1   -1   0   
$EndComp
$Comp
L Device:Buzzer BZ1
U 1 1 60BF82DC
P 5660 1090
F 0 "BZ1" V 5711 903 50  0000 R CNN
F 1 "Buzzer" V 5620 903 50  0000 R CNN
F 2 "Buzzer_Beeper:Buzzer_12x9.5RM7.6" V 5635 1190 50  0001 C CNN
F 3 "~" V 5635 1190 50  0001 C CNN
	1    5660 1090
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small R4
U 1 1 60BF92A7
P 6080 1670
F 0 "R4" H 6139 1716 50  0000 L CNN
F 1 "1K" H 6139 1625 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" H 6080 1670 50  0001 C CNN
F 3 "~" H 6080 1670 50  0001 C CNN
	1    6080 1670
	1    0    0    -1  
$EndComp
Wire Wire Line
	5760 1190 5880 1190
Wire Wire Line
	6080 1570 6080 1490
Text Label 6280 1190 0    50   ~ 0
VSS
Text Label 5560 1190 2    50   ~ 0
VDD
Text Label 6080 1770 3    50   ~ 0
RB7
$EndSCHEMATC
