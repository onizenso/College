read_data = 'rand.csv';
ano = fopen(read_data);
n = csvread(read_data);
n = reshape(n, 20, 20);
