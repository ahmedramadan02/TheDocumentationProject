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