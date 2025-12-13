# 🐴 Knight’s Tour Problem (C++)

Program ini merupakan implementasi penyelesaian **Knight’s Tour Problem** menggunakan bahasa **C++** dengan pendekatan **Backtracking (rekursif)**. Program akan mencari jalur pergerakan bidak kuda pada papan catur berukuran **N × N** sehingga setiap kotak dikunjungi **tepat satu kali**.

---

## 📌 Deskripsi
Knight’s Tour adalah masalah klasik dalam ilmu komputer dan matematika diskrit. Dalam program ini, pengguna dapat menentukan **posisi awal kuda**, kemudian program akan menghitung dan menampilkan urutan langkah kuda hingga seluruh papan catur terjelajahi.

---

## ⚙️ Fitur
- Ukuran papan dapat diubah melalui konstanta `N`
- Posisi awal kuda ditentukan oleh pengguna
- Menggunakan algoritma **Backtracking**
- Menampilkan urutan langkah kuda dalam bentuk matriks
- Menangani kasus tidak adanya solusi

---

## 🛠️ Teknologi
- Bahasa: **C++**
- Compiler: `g++` / Dev-C++
- Library: `<iostream>`, `<iomanip>`

---

## 📥 Input
Pengguna memasukkan dua bilangan bulat:

x y

markdown
Copy code

Keterangan:
- `x` = baris awal kuda
- `y` = kolom awal kuda
- Nilai `x` dan `y` harus berada pada rentang `0` sampai `N-1`

Contoh:
0 0

---

## 📤 Output
- Jika solusi ditemukan, program akan menampilkan papan catur berukuran `N × N` yang berisi angka:
  - `0` → posisi awal kuda
  - Angka berikutnya → urutan langkah kuda
- Jika solusi tidak ditemukan:
No solution exists.
