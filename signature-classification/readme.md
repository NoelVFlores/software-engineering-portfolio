This project was completed by myself along with Chinwe Aghadinuno for our final project of our Brain-inspired AI course.


OBJECTIVE

This deep learning project aims to verify handwritten signatures using "Siamese Neural Networks", comparing a custom-built CNN
model and a pre-trained CNN model. The objective was to determine whether two signature images belong to the same individual
or if one is a forgery, through the use of deep metric learning techniques.


OVERVIEW

- Implements two siamese architectures:
      A Custom CNN with ResNet-inspired design
      A pre-trained CNN model (modified and evaluated)
- Trains and evaluates similarity between image pairs using "contrastive loss" function
- Conducted evalution on "2,200 signature image pairs using 2011 ICDAR dataset
- Achieved 30% increased accuracy with custom model!

TECHNOLOGIES USED
- **Framework**: PyTorch
- **Libraries**: NumPy, Pandas, Matplotlib, Scikit-learn
- **Model Architectures**:
  - Custom ResNet-inspired CNN (64-dimensional embedding)
  - Modified AlexNet-style pre-trained CNN (2-dimensional embedding)
- **Optimizers**: Adam (custom model), RMSProp (pre-trained model)
- **Evaluation Metrics**: Accuracy, Confusion Matrix, TP/FP/FN Analysis


RESULTS

  | Feature               | Custom CNN      | Pre-trained CNN  |
|----------------------|------------------|------------------|
| Embedding Dimension  | 64               | 2                |
| Epochs               | 40               | 20               |
| Batch Size           | 16               | 32               |
| Optimizer            | Adam             | RMSProp          |
| Accuracy             | **70%**          | 30%              |
| Training Time        | ~1 hour (GPU)    | ~2.5 hours (GPU) |
