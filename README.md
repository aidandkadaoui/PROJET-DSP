# PROJET-DSP
Segmentation et classification automatique de chromosomes : Implémentation comparative sur MATLAB et DSP TMS320C6713
## Description
This project presents a complete image processing chain for chromosome segmentation and separation using MATLAB and the DSP TMS320C6713 Starter Kit.

The system performs:
- Image preprocessing
- Noise reduction
- Contrast enhancement
- Thresholding and binarization
- Morphological processing
- Separation of touching chromosomes
- Visualization of DSP results in MATLAB

MATLAB was used for algorithm development and validation, while the DSP platform was used for real-time embedded implementation.

---

# Technologies Used

- MATLAB
- C Language
- Code Composer Studio (CCS)
- DSP TMS320C6713 DSK

---

# Project Structure

```text
├── MATLAB/
│   ├── CODE_matlab_du_projet.m

│
├── DSP/
│   ├── main.c
│   ├── image_data.h
│   └── project_files/
│
├── Images/
│   ├── chromosomes.jpg/
│   └── results.dat/
│
└── README.md
```

---


---

# Included Files

## MATLAB Files
- `main.m` : Main MATLAB script
- `visualization_dsp.m` : Visualize DSP outputs
- `convert_to_c_array.m` : Convert image into C array format

## DSP Files
- `main.c` : Main DSP processing program
- `image_data.h` : Image array header file

---

# How to Run

## MATLAB
Run:

```matlab
main
```

## DSP
1. Open Code Composer Studio
2. Import the DSP project
3. Build the project
4. Load program into TMS320C6713 DSK
5. Run the application

---

# Applications

- Biomedical image processing
- Chromosome analysis
- Cytogenetics
- Embedded image processing systems

---

# Authors

- Fadwa Kadaoui
- Amina Boucenna
  Raouf Aid

---

# Supervisor

Mme Bouchama

---

# License

Academic and educational use only.
