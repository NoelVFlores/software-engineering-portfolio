# Signature Verification Using Siamese Neural Networks (PyTorch)

This project explores handwritten signature verification using Siamese Neural Networks built with PyTorch. The goal was to determine whether two signature images belong to the same individual or are forgeries by comparing learned feature embeddings.

## 🧠 Overview

Two models were implemented and evaluated:
- **Pretrained Siamese CNN Model** (based on AlexNet-like architecture)
- **Custom Siamese CNN Model** (based on ResNet-inspired architecture)

Each model processes pairs of grayscale signature images (105×105) and uses contrastive loss to learn a similarity function based on Euclidean distance between embedding vectors.

## 🔍 Key Features

- **Deep Metric Learning** using Siamese architecture
- **Custom CNN model** with a 64-dimensional embedding for better verification accuracy
- **Contrastive Loss** for genuine vs. forged signature learning
- **Dynamic thresholding** to classify signature pairs
- **Data Augmentation** (brightness/contrast jittering)
- **Confusion Matrix Analysis** for evaluation
- **Training & Evaluation with PyTorch**

## 📊 Results

| Model              | Embedding Size | Accuracy | Runtime | Epochs | Batch Size | Optimizer |
|-------------------|----------------|----------|---------|--------|------------|-----------|
| Pretrained Model  | 2              | 30%      | 2h 36m  | 20     | 32         | RMSProp   |
| Custom Model      | 64             | 70%      | 1h      | 40     | 16         | Adam      |

## 📁 Dependencies

- Python 3.x
- PyTorch
- NumPy
- Pandas
- Matplotlib
- Scikit-learn

## 🧪 Usage

To train the model:
```bash
python train.py
