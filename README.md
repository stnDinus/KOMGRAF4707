# Tugas Komputer Grafik

### Biodata
- Nama: Lie, Steven Staria Nugraha
- NIM: A11.2022.14433
- Kelompok: A11.4707

### Dependencies
- `cmake` ^ `3.27`
- compiler `c++` dengan standard `c++20`
- `OpenGL`
- `GLEW` ^ `2.2.0-6`
- `GLFW` ^ `3.3.8-1`

### Daftar Isi
1. HW1: Screenshot OpenGL
2. HW2: Operasi matriks (penjumlahan, pengurangan, perkalian, invers, pembagian)
3. HW3: DDA (Digital Differential Analyzer)
4. HW4: Bresenham
5. HW5: Transformasi matriks
6. HW6: Translasi matriks, implementasi OpenGL
7. HW7: Transformasi matriks NIM + mirroring
8. UTS: Implementasi UTS
9. HW8: Clipping, implementasi OpenGL
10. Transformasi3D: Transformasi matriks 3 dimensi

---

### Catatan
- Belum di uji coba dalam OS selain linux, setiap dependency seharusnya bersifat cross-platform.
- Disarankan membuat subdirectory `build` dalam masing-masing directory tugas (`HWX`) untuk membuat tugas.
- Untuk menjalankan tugas berkaitan `OpenGL`, pastikan `SHADERS_DIR` terdefinisi saat menjalankan (runtime). Inisialisasikan dengan alamat directory `common` pada respository ini untuk menggunakan shaders bawaan. (e.g. `SHADERS_DIR=../../common ./HW8`, jika menjalankan dari subdirectory `build` dalam `HW8`)
