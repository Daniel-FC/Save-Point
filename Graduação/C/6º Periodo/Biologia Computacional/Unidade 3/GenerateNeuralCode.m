%% Iniciar
clear;
DataParameters;
AccProbabilistics;

tam = ones(1,QtdN);
%% Codigo
for l = 1:(size(Hip,2))

    for c = 1:QtdN

       if Hip(l) == 1

           sorteado = rand(1);
           y = find(wkAC>sorteado, 1);
           varia(c, l) = y; 
           
           ind = round(wkV(y));
           vetor = sort(rand(1, ind));
           matriz(c, tam(c):(tam(c)-1)+ind) = vetor + ((l-1) * HipDt);
           tam(c) = tam(c) + ind;
           vetor = [];
           
       end;

       if Hip(l) == 2

           sorteado = rand(1);
           y = find(swsAC>sorteado, 1);
           varia(c, l) = y;
           
           ind = round(swsV(y));
           vetor = sort(rand(1, ind));
           matriz(c, tam(c):(tam(c)-1)+ind) = vetor + ((l-1) * HipDt);
           tam(c) = tam(c) + ind;
           vetor = [];

       end;

       if Hip(l) == 3  

           sorteado = rand(1);
           y = find(remAC>sorteado, 1);
           varia(c, l) = y;
           
           ind = round(remV(y));
           vetor = sort(rand(1, ind));
           matriz(c, tam(c):(tam(c)-1)+ind) = vetor + ((l-1) * HipDt);
           tam(c) = tam(c) + ind;
           vetor = [];         

       end;      

    end;

end;
FiringRate;
Variation;
%% Transformar Matriz em cecula
for n=1:size(matriz,1)
    cN{n} = matriz(n,1:tam(n)-1);
end
%% Gerar Figura
figure

subplot(3,1,1);
colorm = [ ...
    1 0 0   %blue
    0 0 1   %red
    0 1 0 ];  %green

 plotHypImage_simpler(Hip', ...
                1000, ...
                [], ...
                colorm );
imagesc(Hip);
% Create xlabel
xlabel('Tempo');
% Create ylabel
ylabel('Hipnograma');

hd = subplot(3,1,2);
rasterPlot(hd, cN, QtdN, 1, 2, 0, 0, '');
xlim([0 (size(Hip,2))]);
% Create xlabel
xlabel('Tempo');
% Create ylabel
ylabel('Num. Neurônios');

subplot(3,1,3);
x=1:numel(vetor);
y=(vetor/QtdN);
errorbar(x-1, y, vari);
xlim([0 (size(Hip,2))]);
% Create xlabel
xlabel('Tempo');
% Create ylabel
ylabel('Taxa de disparos mêdios');