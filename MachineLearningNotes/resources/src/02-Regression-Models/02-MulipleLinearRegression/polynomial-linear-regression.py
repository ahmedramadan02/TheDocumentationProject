import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

dataset = pd.read_csv('Position_Salaries.csv')
x = dataset.iloc[:,1:2].values #Note: [:,1:2] instead of direct [:,1] as in ML we needs always the features to be martix not vectors
y = dataset.iloc[:,2].values

# In very small n samples, no need to have test and training set, as it will be no data enough for the training then

