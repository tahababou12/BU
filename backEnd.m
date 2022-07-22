Mx = zeros(size(C,1),size(C,2)); %Horizontal member components
My = zeros(size(C,1),size(C,2)); %Vertical member components

[row,col] = find(C==1); %Finds where the user's truss pin joints' location are
n = zeros(1,length(row)-1);

for i = 1:2:length(row)-1
    Mx(row(i,1),col(i,1))= ((X(1,row(i+1,1))) - (X(1,row(i,1)))) / (sqrt((((X(1,row(i+1,1))) - (X(1,row(i,1))))^2) + ((Y(1,row(i+1,1))) - (Y(1,row(i,1))))^2));
    Mx(row(i+1,1),col(i,1))= ((X(1,row(i,1))) - (X(1,row(i+1,1)))) / (sqrt((((X(1,row(i+1,1))) - (X(1,row(i,1))))^2) + ((Y(1,row(i+1,1))) - (Y(1,row(i,1))))^2));
    
    n(i) = (sqrt((((X(1,row(i+1,1))) - (X(1,row(i,1))))^2) + ((Y(1,row(i+1,1))) - (Y(1,row(i,1))))^2));
    
    My(row(i,1),col(i,1))= ((Y(1,row(i+1,1))) - (Y(1,row(i,1)))) / (sqrt((((X(1,row(i+1,1))) - (X(1,row(i,1))))^2) + ((Y(1,row(i+1,1))) - (Y(1,row(i,1))))^2));
    My(row(i+1,1),col(i,1))= ((Y(1,row(i,1))) - (Y(1,row(i+1,1)))) / (sqrt((((X(1,row(i+1,1))) - (X(1,row(i,1))))^2) + ((Y(1,row(i+1,1))) - (Y(1,row(i,1))))^2));
end

membLength = n(n~=0); %length per member

A = [[Mx Sx];[My Sy]]; %Concatenating Mx,Sx,My,Sy into a single matrix A

T = A\L; %Matrix for unknown forces (Tn:Tm, Sx1, Sy1, Sy2) -> inverse(A) * L
T = round(T,4);
%%%%%%%%%
%Specifications
%Cost/total

J = size(C,1);
LL = 0; %Declaring variable LL for total sum of member lengths

for i = 1:2:length(row)-1
    LL = LL + (sqrt((((X(1,row(i+1,1))) - (X(1,row(i,1))))^2) + ((Y(1,row(i+1,1))) - (Y(1,row(i,1))))^2));
end
%LL is the total length of all members combined (total length of entire truss)

total = (10*J) + (1*LL); %total price to make the truss

%%%%%%%
pCrit = zeros(1,length(T)-3);
wFailure = zeros(1,length(T)-3);

wL = L(find(L>0)); %Finding live load based on Matrix L from input file

for i = 1:length(T)-3
    Rm = T(i)/wL;
    pCrit = 2570/(membLength(i)^2); %membLength = length per member
    wFailure(i) = abs(-pCrit / Rm);
end
finalFail = min(wFailure);

loadMaxRatio = finalFail/total;
