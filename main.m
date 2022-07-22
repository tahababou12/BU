backEnd;

fprintf('\n%s',"\% EK301, Section A3, Group 1: Taha H.A., Joel A., Ramy A., 11/12/2021.")

fprintf('\n\nLoad: %d oz',wL)

fprintf('\n\nMember forces in oz:\n')
for i =1:length(T)-3
    if T(i,1) > 0
        tC = "(T)";
    elseif T(i,1) < 0
        tC = "(C)";
    else
        tC = " ";
    end
    fprintf('m%d: %.3g %s \n', i, abs(T(i,1)),tC) % FIX: SAY IF THE FORCE MEMBER IS IN COMPRESSION (C) OR TENSION (T)
end

fprintf('\nReaction forces in oz:\n')
fprintf('Sx1: %d \n', T(length(T)-2,1))
fprintf('Sy1: %.3g \n', T(length(T)-1,1))
fprintf('Sy2: %.3g \n', T(length(T),1))

fprintf('\nCost of truss: $%.3g \n',total) %FIX COST CODE FOR CORRECT VALUE
fprintf('Theoretical max load/cost ratio in oz/$: %.3g \n',loadMaxRatio)