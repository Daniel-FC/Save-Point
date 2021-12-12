wkAC = wkP(1);
for i = 2:(size(wkP,2))
    wkAC(i) = wkP(i) + wkAC(i-1);
end;

swsAC = swsP(1);
for i = 2:(size(swsP,2))
    swsAC(i) = swsP(i) + swsAC(i-1);
end;

remAC = remP(1);
for i = 2:(size(remP,2))
    remAC(i) = remP(i) + remAC(i-1);
end;