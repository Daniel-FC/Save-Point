vetor = zeros(1,size(Hip,2)); 
for i=1:size(Hip,2)
    
    for l=1:size(matriz,1)
        
        for c=1:size(matriz,2)

            if(matriz(l,c)<=(i*HipDt) && matriz(l,c)>(i*HipDt)-HipDt)
              vetor(i) = vetor(i) + 1;

            end

        end
    
    end

end