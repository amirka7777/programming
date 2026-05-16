import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('time.csv')
print("Данные:")
print(df)

plt.figure(figsize=(12, 7))

colors = {1: 'blue', 2: 'green', 4: 'orange', 8: 'red'}
markers = {1: 'o', 2: 's', 4: '^', 8: 'D'}

for threads in sorted(df['threads'].unique()):
    subset = df[df['threads'] == threads]
    plt.plot(subset['size'], subset['time_sec'],
             marker=markers[threads],
             color=colors[threads],
             linewidth=2,
             markersize=8,
             label=f'{threads} потоков')

plt.xlabel('Размер матрицы (N)', fontsize=12)
plt.ylabel('Время выполнения (секунды)', fontsize=12)
plt.title('Зависимость времени умножения матриц от размера и количества потоков', fontsize=14)
plt.legend(loc='upper left', fontsize=10)
plt.grid(True, alpha=0.3)

plt.tight_layout()
plt.savefig('pictures/graph.png', dpi=150)
plt.show()