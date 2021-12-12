%% ploting a raster plot and firing rate
% HH_blanco
% Parameters:
%   mSpikeTime: matriz of spike times. It is a matlab cell struture of one
%   dimesion mSpikeTimes{1.. nNeurons}, in which each row have a vector
%   with the time value where the spike occured.
%
%   vnExcNeurons: Amount of excitarory neurons ex: 80 means that from 1:80
%   are excitatory neurons. It also could be a vector from {1.. nNeurons}
%   with values 0 or 1, zeros are the inhibitory neurons and 1s are the
%   excitatory neurons.
% 
%
%   timeScale: time scale. Usually in miliseconds => 1000
%
%   lineWith: line width
%
%   countAct: flag value (0,1) to plot a firing rate subplot
%
%   timeRange: vector with two values (min, max) representing the time range of
%   values to visualize the plots. The default value is 0, then the entire
%   time is taken.
function rasterPlot( gcaHandle, mSpikeTimes, vnExcNeurons, timeScale, lineWidth, countAct, timeRange, marker)

nNeurons = numel(mSpikeTimes);

if (isempty(marker))
    marker = '.';
end
maxTime=0;
for n = 1:nNeurons
    maxT = max(mSpikeTimes{n});
    if (maxT > maxTime)
        maxTime = maxT;
    end
end

if (gcaHandle == [])
    fh = figure('Color',[1 1 1], ...
        'Position', [50 50 1600 1050]);hold on
end;
if (countAct==1)
    subplot(2,1,1);
end
hold on
for n = 1:nNeurons
    vSpikes = mSpikeTimes{n};
    nSpikes = numel(vSpikes);
    y = n*ones(1,nSpikes);
    %        yline = [(n-1)*ones(1,nSpikes); n*ones(1,nSpikes)];
    if (numel(vnExcNeurons)==1)
        if (n<=vnExcNeurons)
            neuColor = 'r';
        else
            neuColor = 'b';
        end
    elseif (vnExcNeurons(n)==1)
        neuColor = 'r';
    else 
        neuColor = 'b';       
    end
    plot(vSpikes/timeScale, y, [neuColor marker], ...
        'LineWidth',lineWidth);
end
if (timeRange == 0)
    xlim([0 maxTime/timeScale])
else
    xlim([timeRange(1)/timeScale timeRange(2)/timeScale])
end
ylim([0 nNeurons])
if (gcaHandle ~= [])
    ylabel(['\fontsize{16} ' num2str(nNeurons) ' Neurons <{\color{red}' num2str(vnExcNeurons) ' Exc}, {\color{blue} ' num2str(nNeurons-vnExcNeurons) ' Inh} >']);
    xlabel('\fontsize{16} Time (s)');
end

if (countAct ==1)
    binTime  = 2; % ms
    xbins = 1:binTime:maxT;
    countExc = zeros(1,numel(xbins));
    countInh = zeros(1,numel(xbins));
    for n = 1:nNeurons
        x = mSpikeTimes{n};
        [counts,centers] = hist(x,xbins);
        if (n<=vnExcNeurons)
            countExc = countExc + (counts>=1);
        else
            countInh = countInh + (counts>=1);
        end
    end
    
    subplot(2,1,2);
    hold on
    plot(centers/timeScale, countExc/nNeurons, 'r-');
    plot(centers/timeScale, countInh/nNeurons, 'b-');
    % plot(centers/timeScale, countExc - countInh,'g-');
    
    if (timeRange == 0)
        xlim([0 maxTime/timeScale])
    else
        xlim([timeRange(1)/timeScale timeRange(2)/timeScale])
    end
    ylim([0 1])
    xlabel('\fontsize{16} Time (s)');
end


end
