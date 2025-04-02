import pandas as pd
import matplotlib.pyplot as plt

# load data
data = pd.read_csv('../assets/csv/stern_brocot_vectors.csv')
data.columns = data.columns.str.strip()

# square plot
fig, ax = plt.subplots()
ax.set_aspect('equal', adjustable='box')  # Set aspect ratio to be equal
fig.set_size_inches(6, 6)  # Optionally adjust the figure size to square dimensions

# vectors
for index, row in data.iterrows():
    tail_x = row['tail_x']
    tail_y = row['tail_y']
    head_x = row['head_x']
    head_y = row['head_y']
    
    ax.plot([tail_x, head_x], [tail_y, head_y], color='black', linewidth=0.5)

# set the axis limits
plt.xlim(0, 10)
plt.ylim(0, 10)

# grid, labels and title
plt.grid(True)
plt.xlabel('Numerators')
plt.ylabel('Denominators')

# save the figure
plt.savefig('../assets/png/stern_brocot_vector.png', dpi=300)
plt.close()
