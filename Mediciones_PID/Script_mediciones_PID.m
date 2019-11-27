%Script de prueba de mediciones del PID_control

clear all;
close all;
clc;

DATA = dlmread("Prueba_1.txt"); %Cargo los datos de la prueba 1
DATA2 = dlmread("Prueba_2.txt");%Cargo los datos de la prueba 2
DATA_ACTUADOR_2 = dlmread("Actuador_prueba_2.txt");%Cargo los datos del actuador
DATA3 = dlmread("Prueba_3.txt");%Cargo los datos de la prueba 3
DATA4 = dlmread("Prueba_4.txt");%Cargo los datos de la prueba 4
DATA5 = dlmread("Prueba_5.txt");%Cargo los datos de la prueba 5
DATA6 = dlmread("Prueba_6.txt");%Cargo los datos de la prueba 6
DATA7 = dlmread("Prueba_7.txt");%Cargo los datos de la prueba 7
DATA8 = dlmread("Prueba_8.txt");%Cargo los datos de la prueba 8
n8 = length(DATA8);
n7 = length(DATA7);
n6 = length(DATA6);
n5 = length(DATA5);
n4 = length(DATA4);
n3 = length(DATA3);
na2 = length(DATA_ACTUADOR_2);
n2 = length(DATA2);
n = length(DATA);
t = [0:1:n-1];
T = 1; %Segundo
t = t * T;

t2 = [0:1:500];


KP = 10; %Constante proporcional
alfa = 0.01;  %Posición del cero que va con el polo en el origen
KI = alfa  * KP;  %Constante integral
KT = 1; %Constante de corrección anti windup

%Ajuste de datos a sistema de primer orden
f = @(T0,tau) T0*(1-exp(-t./tau)) + 153;  %Función a ajustar

err = @(x) norm(DATA - f(x(1),x(2)));
xo = [30, 0.1];
options = optimset('MaxIter',10);
x = fminsearch(err,xo,options);

T0 = x(1);
tau = x(2);

%Con estos datos puedo despejar un primer modelo de la planta

s = tf('s');

H = 0.1 * (0.85 * s + 0.027)/(0.15 * s + 3e-3); %Modelo de planta
G = H * KP/(1+H*KP);              %Modelo a lazo cerrado con ganancia proporcional

%Para que llegue a los 180 °C le tengo que agregar un control integral
G2 = H*(KP + KI / s)/(H*(KP + KI/s) + 1);

escalon = ones(1,length(t2)) * 180;
escalon(1) = 150;
[Y,T,X] = lsim(G2,escalon,t2);

%Grafico de la aproximación de planta controlada

figure
hold on;
plot(T,Y,'k-','Linewidth',3);
grid on;
xlabel("tiempo [s]");
ylabel("temp [°C]");
title("Respuesta al escalón del sist realimentado teórica");
ylim([150 185]);
leyenda1 = sprintf("KP = %.1f, KI = %.3f, KT = 1",KP,KI);
legend(leyenda1);

%Grafico de los datos de la primera medición
%y de la regresión a una planta de primer orden

figure
hold on;
plot(t,DATA,'r-','Linewidth',3);
hold on;
plot(t,T0 * (1-exp(-t/tau)) + 153,'b-','Linewidth',3);
xlabel("tiempo [s]");
ylabel("temp [°C]");
grid on;
title("Ajuste del sist realimetado a T(t) = T0 * (1 - e^{-t/tau}) + 153, para un escalón de 180 °C");
xlim([0 t(n)]);
leyenda1 = sprintf("Datos de mediciones: KP = %i, KI = %i, KT = %i",10,0,1);
leyenda2 = sprintf("Ajuste de datos: T0 = %.1f, tau = %.1f",T0,tau);
legend(leyenda1,leyenda2);

%Grafico de las segundas mediciones con KP = 10, KI = 0.1, KT = 5

tdata2 = [0:1:n2-1];
%tdataa2 = [0:1:na2-1-97];
%figure
%hold on;
%plot(tdata2,DATA2);
%grid on;


%Grafico de la tercera medición con KP = 5, KI = 0.05, KT = 5

tdata3 = [0:1:n3-1];
%figure
%hold on;
%plot(tdata3,DATA3);

%Grafico de la cuarta medicion KP = 10, KI = 0.1, KT = 1

tdata4 = [0:1:n4-1];
%figure
%hold on;
%plot(tdata4,DATA4);

%Grafico de la quinta medicion KP = 10, KI = 0.1, KT = 5

tdata5 = [0:1:n5-1];
%figure
%hold on;
%plot(tdata5,DATA5);

%Grafico de las demás mediciones

tdata6 = [0:1:n6-1];
tdata7 = [0:1:n7-1];
tdata8 = [0:1:n8-1];

figure
hold on;
plot(tdata2,DATA2,'linewidth',3);
hold on;
plot(tdata3,DATA3,'linewidth',3);
hold on;
plot(tdata4,DATA4,'linewidth',3);
hold on;
plot(tdata5,DATA5,'linewidth',3);
hold on;
plot(tdata6,DATA6,'linewidth',3);
grid on;
leyenda2 = sprintf("KP = %.1f, KI = %.1f, KT = %.1f",10,0.1,5);
leyenda3 = sprintf("KP = %.1f, KI = %.1f, KT = %.1f",5,0.05,5);
leyenda4 = sprintf("KP = %.1f, KI = %.1f, KT = %.1f",10,0.1,1);
leyenda5= sprintf("KP = %.1f, KI = %.1f, KT = %.1f",10,0.1,5);
leyenda6 = sprintf("KP = %.1f, KI = %.1f, KT = %.1f",10,0.1,5);
legend(leyenda2,leyenda3,leyenda4,leyenda5,leyenda6,'location','east');
xlabel("tiempo [s]");
ylabel("temp [°C]");
title("Comparación de diferentes pruebas de constantes");

%Se modificó el algoritmo de anti windup para que en lugar de KT tenga KT * KI

figure
hold on;
plot(tdata6,DATA6,'linewidth',3);
hold on;
plot(tdata7,DATA7,'linewidth',3);
grid on;
leyenda1 = sprintf("KP = %.1f, KI = %.1f, KT = %.1f",10,0.1,5);
leyenda2 = sprintf("KP = %.1f, KI = %.1f, KT = %.1f",10,0.1,1);
title("Modificación del algoritmo anti windup");
xlabel("tiempo [s]");
ylabel("temp [°C]");
legend(leyenda1,leyenda2,'location','east');

%Se modificó y se cambiaron todas las varaibles a float
%Se grafica el resultado mejor obtenido usando
%variables enteras y floats
%Ambos tienen las mismas constantes

figure
hold on;
plot(tdata7,DATA7,'linewidth',3);
hold on;
plot(tdata8,DATA8,'linewidth',3);
leyenda1 = sprintf("Variables enteras");
leyenda2 = sprintf("Variables floats");
title("Modificación del tipo de variables usadas");
xlabel("tiempo [s]");
ylabel("temp [°C]");
legend(leyenda1,leyenda2,'location','east');
grid on;









