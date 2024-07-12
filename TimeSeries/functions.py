
from statsmodels.tsa.stattools import adfuller, kpss


def adf(x):
    
    adf,pvalue,usedlag_,nobs_,critical_values_,icbest_= adfuller(x)
    if pvalue <0.05:
        print("O dado é estacionário, pvalue = ", pvalue)
    else:
        print("O dado não é estacionário")
        
        

# STATIONARY

def KPSS(x):
    result = kpss(x, regression='c')
    print('KPSS Statistic: %f' % result[0])
    print('p-value: %f' % result[1])
    if result[1]<0.05:
        print("Não estacionária")
    else:
        print("Estacionária")
