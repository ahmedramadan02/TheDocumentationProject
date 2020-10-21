import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

dataset = pd.read_csv('Data.csv')
# The features
x = dataset.iloc[:,:-1].values

# the dependent varaible
y = dataset.iloc[:,-1].values

# Dealing with the missing data
from sklearn.impute import SimpleImputer
imputer = SimpleImputer(missing_values=np.nan, strategy='mean')

#Apply the the mean for all the missing values on both
#age and salary
imputer.fit(x[:, 1:3])
x[:, 1:3] = imputer.transform(x[:, 1:3])

#Create one hot encoder for the country
#but Labal encoder for the purchased
from sklearn.compose import ColumnTransformer
from sklearn.preprocessing import OneHotEncoder

#Transfomers is a set of paramters (list of tuples)
# Type = Encoder, onehotencoder, the index of the values need to be included, whihc is the country column
# Reminder; By default, only the specified columns in transformers are transformed and combined in the output, and the non-specified columns are dropped. (default of 'drop').
# By specifying remainder='passthrough', all remaining columns that were not specified in transformers will be automatically passed through.
ct = ColumnTransformer(transformers=[('encoder', OneHotEncoder(),[0])],remainder='passthrough')
# we convert the output from the fit_transform to a numpy arry style for future
x = np.array(ct.fit_transform(x))

from sklearn.preprocessing import LabelEncoder
le = LabelEncoder()
# no need to numpy array from 
y = le.fit_transform(y)

# Feature scaling
from sklearn.preprocessing import StandardScaler
sc = StandardScaler()
x = sc.fit_transform(x)

# Import the train_test_split function
# It returns 4 elements: x_training x_test y_training y_test
from sklearn.model_selection import train_test_split
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2, random_state=0)

print(x_train)
print(x_test)
print(y_train)
print(y_test)