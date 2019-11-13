clear all;
close all;
clc;

%Vcc = 5;
%B = 4000;
%T0 = 25+273;
%R0 = 100e3;
%R = 1.25e3;
%T = [25:0.17:250] + 273;
%
%Rth = R0 * exp((B./T) - (B/T0));
%Vth = (Vcc * Rth)./(Rth + R);
%
%%Linealización alrededor de 180 grados
%
%V = 2.13 - 34.1e-3 * (T-453);
%
%
%figure
%hold on;
%plot(T-273,Vth,'bo','Markersize',5);
%hold on;
%plot(T-273,V,'ro','Markersize',5);
%grid on;
%%xlim([150 200]);
%
%%%%Dibujo con Rth arriba
%R1 = 14.5e3;
%V2 = Vcc * R1./(R1 + Rth);
%
%figure
%hold on;
%plot(T-273,V2,'bo','Markersize',5);

Vcc = 5;                  %Volts
R1 = 270;              %Ohms
R2 = 1e3;                 %Ohms
R3 = 1.1e3;                 %Ohms
V2 = 1.2;                 %Volts
T = [25:5:250] + 273;  %Kelvin
B = 4000;
T0 = 25+273;
R0 = 100e3;
Rth = R0 * exp((B./T) - (B/T0));

Vin = Vcc * R1 ./(R1 + Rth);

Vo = Vin * (1+R3/R2) - V2 * R3/R2;



%figure
%hold on;
%plot(T-273,Vo,'bo','Markersize',8);
%
%
%grid on;
%xlabel("T [°C]");
%ylabel("Tensión que lee el ADC [V]");
%title("Linealización del uso del termistor para medir temperaturas");
%xlim([150 250]);

%%%Prubea con divisor resistivo

Ra = 4.7e3;
Rb = 1.5e3;

Vo = Vin * (1+R2/Ra + R2/Rb) - 5 * (R2/Ra);

figure
hold on;
plot(T-273,Vo,'bo','Markersize',8);


grid on;
xlabel("T [°C]");
ylabel("Tensión que lee el ADC [V]");
title("Linealización del uso del termistor para medir temperaturas:divisor resistivo");
xlim([150 250]);



