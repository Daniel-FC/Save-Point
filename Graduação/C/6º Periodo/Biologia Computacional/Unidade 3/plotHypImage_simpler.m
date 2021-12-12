% hypVector => Hypnogram values vector. This parameter is mandatory.
% origStepHyp => Original value (in ms) of the time step for the hypnogram. 
% rangeOfTime => Vector of two columns to define the range of the time to
%                be exposed. They are double values in ms and they must be greater than zero.
%                Example: [250 800000]
%                Use [] to retrieve all the domain.      
% colorm => Matrix (n,3) with three columns representing the (r g b) color
%           components and N lines. N represents the amount of colors for the color
%           map.
function v = plotHypImage_simpler( hyp, ...
                            origStepHyp, ...
                            rangeOfTime, ...
                            colorm )

    hyp = hyp';
     
    v = hyp;
    if (origStepHyp <=0)
        origStepHyp = 1000; %1000 ms => 1s
    end
    
    if (~isempty(rangeOfTime))
        startInd = round(rangeOfTime(1)/origStepHyp);
        if (startInd <= 0) %cheking rights values
            startInd = 1;
        end
        endInd = round(rangeOfTime(2)/origStepHyp);
        if (endInd <= startInd) %cheking rights values
            endInd = round(size(v,1)*origStepHyp);
        end
        v = v(startInd:endInd);
    else
        startInd = 0;
        endInd = round(size(v,1)*origStepHyp);
    end
         
    imagesc( rangeOfTime, [1 10] ,v);
    set(gca,'xtick',[],'ytick',[])
    colormap(colorm);
    %colorbar
end