import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

dataset = pd.read_csv('50_Startups.csv')
# The features
x = dataset.iloc[:,:-1].values
y = dataset.iloc[:,4].values

#Create one hot encoder for the country
from sklearn.preprocessing import LabelEncoder, OneHotEncoder
#In order to apply the onehotencoder, we need first to convert the text into numbers
labelencoder_X = LabelEncoder()
x[:,3] = labelencoder_X.fit_transform(x[:,3])
#Apply the onehotencoder to have the dummy varaibles
onehotencoder = OneHotEncoder(categorical_features= [3])
x = onehotencoder.fit_transform(x).toarray()

#Avoiding the dummy varaible traps
x = x[:, 1:] #take all the columns from 1 to the end, ignore 0

# It returns 4 elements: x_training x_test y_training y_test
from sklearn.model_selection import train_test_split
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2, random_state=0)

#Note: no need to make scaling, it will be done automatically in the mutli-linear regression algorithm
#Fitting the multiple linear regression to the training set
from sklearn.linear_model import LinearRegression
mlregressor = LinearRegression()
mlregressor.fit(x_train, y_train)

# Check the efficiency by the test set
y_predicted = mlregressor.predict(x_test)

# Using backward elimination
import statsmodels.api as sm
# as this is needed by statsmodels library, we first need to have b0x0 (the const coeff) in our equation
# as we don't have b0 in our equation, then we will add a column of ones
x = np.append(arr = np.ones((50, 1)).astype(int), values = x, axis = 1)

# Including all the features at the beginning
# Remove the one with least signficant one by one
#You need to convert into float otherwise all ones!
x_optimal = np.array(x[:, [0, 1, 2, 3, 4, 5]], dtype=float)
# STEP1: Select a significance level to stay in the model (default SL = 0.05)
# STEP2: Fit the full model with all possible predictors using stats model library (using regressor class Ordinary Least Squares)
regressor_ols = sm.OLS(endog = y, exog = x_optimal).fit()
#STEP3: Get for each independent varaible its p-Value, and check to remove or not
regressor_ols.summary()

# Looking at the summary, we need to remove the indexes with highest P-Value (here x2)
x_optimal = np.array(x[:, [0, 1, 3, 4, 5]], dtype=float)
regressor_ols = sm.OLS(endog = y, exog = x_optimal).fit()
regressor_ols.summary()

# Looking at the summary, we need to remove the indexes with highest P-Value (here x1)
x_optimal = np.array(x[:, [0, 3, 4, 5]], dtype=float)
regressor_ols = sm.OLS(endog = y, exog = x_optimal).fit()
regressor_ols.summary()

# Looking at the summary, we need to remove the indexes with highest P-Value (here x4)
x_optimal = np.array(x[:, [0, 3, 5]], dtype=float)
regressor_ols = sm.OLS(endog = y, exog = x_optimal).fit()
regressor_ols.summary()

# Looking at the summary, we need to remove the indexes with highest P-Value (here x5)
x_optimal = np.array(x[:, [0, 3]], dtype=float)
regressor_ols = sm.OLS(endog = y, exog = x_optimal).fit()
regressor_ols.summary()

#Summary the highest signficance varaible on the "profit" is the R&D only !
#Note: also for the x5 ("Marketing"), you can notice that finally it has p-Value = 0.060 ~ 0.05 (our SL)
# If we need more certainity either to remove or not, we can use other values beside the p-Value => Adj. R-squared, and R-squared

# AUTOMATIC WAY TO REMOVE VARAIBLES WITH HIGHEST P-VALUE
import statsmodels.api as sm
def backwardElimination(x, sl):
    numVars = len(x[0])
    for i in range(0, numVars):
        regressor_OLS = sm.OLS(y, x).fit()
        maxVar = max(regressor_OLS.pvalues).astype(float)
        if maxVar > sl:
            for j in range(0, numVars - i):
                if (regressor_OLS.pvalues[j].astype(float) == maxVar):
                    x = np.delete(x, j, 1)
    regressor_OLS.summary()
    return x
 
SL = 0.05
x_opt = x[:, [0, 1, 2, 3, 4, 5]]
x_Modeled = backwardElimination(x_opt, SL)

#USE the Adj. R-squared, and R-squared
import statsmodels.api as sm
def backwardElimination_r(x, SL):
    numVars = len(x[0])
    temp = np.zeros((50,6)).astype(int)
    for i in range(0, numVars):
        regressor_OLS = sm.OLS(y, x).fit()
        maxVar = max(regressor_OLS.pvalues).astype(float)
        adjR_before = regressor_OLS.rsquared_adj.astype(float)
        if maxVar > SL:
            for j in range(0, numVars - i):
                if (regressor_OLS.pvalues[j].astype(float) == maxVar):
                    temp[:,j] = x[:, j]
                    x = np.delete(x, j, 1)
                    tmp_regressor = sm.OLS(y, x).fit()
                    adjR_after = tmp_regressor.rsquared_adj.astype(float)
                    if (adjR_before >= adjR_after):
                        x_rollback = np.hstack((x, temp[:,[0,j]]))
                        x_rollback = np.delete(x_rollback, j, 1)
                        print (regressor_OLS.summary())
                        return x_rollback
                    else:
                        continue
    regressor_OLS.summary()
    return x
 
SL = 0.05
x_opt_r = x[:, [0, 1, 2, 3, 4, 5]]
x_Modeled_r = backwardElimination_r(x_opt_r, SL)