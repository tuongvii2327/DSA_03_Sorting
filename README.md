# DSA-Sorting-Project
## 1. Mở github codespace trong branch test
## 2. Mở terminal (Ctrl + `) và chạy dòng lệnh bên dưới để biên dịch
> cd source

> g++ *.cpp -std=c++17 -o 03 (03 là tên nhóm)
## 3. Nên dùng command 2 (với kích thước lớn) hoặc command 3 (với kích thước nhỏ) để chạy
Ví dụ:
Command 2: ./03 -a [Algorithm] [Input_size] [Input_order] [Output_parameter]
> ./03 -a quick-sort 10000 -rand -both

Command 3: ./03 -a [Algorithm] [Input_size] [Output_parameter]
> ./03 -a quick-sort 10000 -both
- Lưu ý: luôn để [Output_parameter] là "-both"

## 4. Ghi lại kết quả trong sheet và kiểm tra tính hợp lý (nhớ tô màu dữ liệu để phân biệt)
## 5. Note:
- Các kích thước dữ liệu cần đo là: 10,000, 30,000, 50,000, 100,000, 300,000, and 500,000
- Các kiểu dữ liệu cần đo là: -sorted , -nsorted , -rev , -rand
- Các thuật toán:
  - Duy: shaker-sort, counting-sort, quick-sort, binary-insertion-sort
  - Mai: insertion-sort, radix-sort, merge-sort, flash-sort 
  - Vi: bubble-sort, shell-sort, heap-sort, selection-sort
