import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# load data
data = pd.read_csv('../assets/csv/stern_brocot_data.csv')
data.columns = data.columns.str.strip()

# figure and axis
fig, ax = plt.subplots()
ax.set_aspect('equal', adjustable='box')  # Set aspect ratio to be equal
fig.set_size_inches(6, 6)  # Optionally adjust the figure size to square dimensions

# circle
circle = plt.Circle((0, 0), 1, edgecolor='black', facecolor='none', linewidth=0.5)  # Increased size and set linewidth
ax.add_artist(circle)

# lines
for index, row in data.iterrows():
    angle = row['angle']
    red = row['r']
    green = row['g']
    blue = row['b']
    
    # end of the vector
    x_end = 1 * np.cos(angle)
    y_end = 1 * np.sin(angle)
    
    # plot the line (vector) from the center to the circle
    ax.plot([0, x_end], [0, y_end], color=(red, green, blue))

# set limits and grid
ax.set_xlim(-1.15, 1.15)
ax.set_ylim(-1.15, 1.15)

# remove tick labels
ax.set_xticks([])
ax.set_yticks([])
    
# remove grid lines and numeric axes markings, keep axes visible
plt.axhline(0, color='black', linewidth=0.5)
plt.axvline(0, color='black', linewidth=0.5)

# save the figure
plt.savefig('../assets/png/stern_brocot_data16.png', dpi=300)
plt.close()
