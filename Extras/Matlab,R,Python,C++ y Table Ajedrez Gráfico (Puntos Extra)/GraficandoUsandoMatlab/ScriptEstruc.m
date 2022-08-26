%/*
	%*Universidad de las Fuerzas Armadas "ESPE"
   
     %*Autores:
    %    De Veintemilla Luca
	%Iza Christopher
	%Rea Denise
	%Vargas Kevin
	%*Fecha de creacion: 
     %   * 18-08-2022
	%*Fecha de modificacion:
   %     * 19-08-2022
  %  *GitHub del grupo:	
 %       https://github.com/ChristopherIza/GrupoParcial3.git
%*/
    fid=fopen('CLineal.txt','rt');
    fid2=fopen('CCuadratica.txt','rt');
    fid3=fopen('CExponencial.txt','rt');
    fid4=fopen('CLinealLogaritmica.txt','rt');
    fid5=fopen('CContinua.txt','rt');
    A=textscan(fid,'%f%f', 'HeaderLines',1);
    B=textscan(fid2,'%f%f','HeaderLines',1);
    C=textscan(fid3,'%f%f','HeaderLines',1);
    D=textscan(fid4,'%f%f','HeaderLines',1);
    E=textscan(fid5,'%f%f','HeaderLines',1);
    fclose('all');
    YR=cell2mat(A);
    YR2=cell2mat(B);
    YR3=cell2mat(C);
    YR4=cell2mat(D);
    YR5=cell2mat(E);
    
    plot(YR(:,1),YR(:,2)/1.1,'DisplayName','Lineal (n)')
    hold all
    plot(YR2(:,1)/1.5,YR2(:,2)/160000,'DisplayName','Cuadratica (n^2)')
    plot(YR3(:,1)/1.5,YR3(:,2)/160000,'DisplayName','Exponencial (2^n)')
    plot(YR4(:,1),YR4(:,2)/150,'DisplayName','Lineal Logaritmico (n log(n))')
    plot(YR5(:,1),YR5(:,2)*10,'DisplayName','Continua (1)')
    legend
    xlabel('Datos') 
    ylabel('Tiempo de ejecución')