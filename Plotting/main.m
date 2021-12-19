clear;
clc;
close all;

color_quicksort = 'b';
color_heapsort = [0,0.5,0];
color_bubblesort = 'r';

% random = "Times/Oscar_2/Random/01random_array_qsort_std.txt";
% sorted = "Times/Olav/Sorted/qsort_sorted_lin.txt";
% reverse_sorted = "Times/Olav/Reverse_Sorted/qsort_reverse_sorted_lin.txt";
% unique_random = "Times/Oscar_2/Unique_Random/01shuffle_qsort_std.txt";
% almost_sorted = "Times/Oscar_2/Almost_Sorted/01almostsorted_qsort_std.txt";

% bubblesort = "Times/Oscar_1/Random/bubblesort.txt";
% heapsort = "Times/Oscar_2/Almost_Sorted/01almostsorted_heapsort.txt";
% quicksort = "Times/Oscar_2/Almost_Sorted/01almostsorted_quicksort.txt";
% std_qsort = "Times/Oscar_2/Almost_Sorted/01almostsorted_qsort_std.txt";

% filename_array = [random, sorted, reverse_sorted, unique_random, almost_sorted];
% filename_array = [random, unique_random, almost_sorted];
% filename_array = [sorted, reverse_sorted];
% filename_array = [random, unique_random, almost_sorted];
% filename_array = [heapsort, quicksort];
% filename_array = [heapsort, quicksort, std_qsort];
% filename_array = [heapsort, std_qsort];
% filename_array = [bubblesort, quicksort];

% hold on
% for filename = filename_array
%     A = importdata(filename);
%     x = A(:, 1);
%     y = A(:, 2);
%     plot(x, y, '*');
% end
% hold off

% legend('Random', 'Sorted', 'Reverse Sorted', 'Uniquely Random', 'Almost Sorted');
% legend('Random', 'Uniquely Random', 'Almost Sorted');
% legend('Sorted', 'Reverse Sorted');
% legend('Random', 'Uniquely Random', 'Almost Sorted');
% legend('Heapsort', 'Quicksort');
% legend('Heapsort', 'Quicksort', 'std::qsort');
% legend('Heapsort', 'std::qsort');
% legend('Bubblesort', 'Quicksort');
% legend('Heapsort', 'Quicksort', 'std::qsort');
% grid;
% title('Comparison, Almost Sorted Array');
% xlabel( 'x = number of elements');
% ylabel( 'y = time (clock ticks)');


% filename = "Times/Oscar_2/Almost_Sorted/01almostsorted_qsort_std.txt";

% A = importdata(filename);
% x = A(:, 1);
%x = log2(A(:, 1));
% y = A(:, 2);
%y = log2(A(:, 2));


% logfit(x, y);
%squarefit(x, y);
% legend off;
% title('std::qsort, Almost Sorted Array');

