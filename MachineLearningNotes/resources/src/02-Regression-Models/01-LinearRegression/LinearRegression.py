import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

dataset = pd.read_csv('Salary_Data.csv')

x = dataset.iloc[:,:-1].values
y = dataset.iloc[:,-1].values

from sklearn.model_selection import train_test_split
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2, random_state=0)

#Simple linear regression
from sklearn.linear_model import LinearRegression
lregressor = LinearRegression()
lregressor.fit(x_train, y_train) # Train it

y_predicted = lregressor.predict(x_test)

# visualize the results
#Visualize the training set results
plt.scatter(x_train, y_train, color='red')
#plot the regression line for the training set
plt.plot(x_train, lregressor.predict(x_train), color='blue')
plt.title('Salary vs Experience (Training set)')
plt.xlabel('Years of experience')
plt.ylabel('Salary')
plt.show()

#Visualize the test set results
plt.scatter(x_test, y_test, color='green')
#plot the regression line for the test set
# The regression line is the same for the xtrain, and xtest
plt.plot(x_train, lregressor.predict(x_train), color='blue')
plt.title('Salary vs Experience (test set)')
plt.xlabel('Years of experience')
plt.ylabel('Salary')
plt.show()