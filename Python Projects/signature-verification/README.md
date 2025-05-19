# Signature Verification Using Siamese Neural Networks (PyTorch, Jupyter Notebooks)

This project explores handwritten signature verification using Siamese Neural Networks built with PyTorch and implemented in Jupyter Notebooks. The objective was to determine whether two signature images belong to the same individual or are forgeries by comparing their learned feature embeddings.

## 🧠 Overview

Two models were implemented and evaluated in separate notebooks:
- **Pretrained Siamese CNN Model** (based on an AlexNet-like architecture)
- **Custom Siamese CNN Model** (inspired by ResNet architecture)

Each model processes pairs of grayscale signature images (105×105) and uses contrastive loss to learn a similarity function based on Euclidean distance between embedding vectors.

## 🔍 Key Features

- **Implemented in Jupyter Notebooks** for interactive experimentation and visualization
- **Deep Metric Learning** using Siamese architecture
- **Custom CNN model** with 64-dimensional embedding for improved verification
- **Contrastive Loss** for genuine vs. forged signature learning
- **Dynamic thresholding** for classification
- **Data Augmentation** (brightness/contrast jittering)
- **Confusion Matrix Analysis** for performance evaluation
- **GPU acceleration using PyTorch**

## 📊 Results

| Model              | Embedding Size | Accuracy | Runtime | Epochs | Batch Size | Optimizer |
|-------------------|----------------|----------|---------|--------|------------|-----------|
| Pretrained Model  | 2              | 30%      | 2h 36m  | 20     | 32         | RMSProp   |
| Custom Model      | 64             | 70%      | 1h      | 40     | 16         | Adam      |

## 📁 Dependencies

- Python 3.x
- Jupyter Notebook
- PyTorch
- NumPy
- Pandas
- Matplotlib
- Scikit-learn

## 🧪 Usage

To run the project, open and execute the notebooks in order:

```bash
jupyter notebook
