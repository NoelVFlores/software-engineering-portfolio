# Software Engineering Portfolio

Welcome to my **Software Engineering Portfolio**!  
This repository showcases a selection of projects that demonstrate my skills in full-stack web development, backend systems, and deep learning.

---

##  Projects Overview

### 1. MERN Job Board
A full-stack job portal built with the **MERN stack** (MongoDB, Express.js, React, Node.js), incorporating **AWS Cognito** for secure authentication and role-based access.

**Highlights:**
- Authentication via AWS Cognito with Admin/User roles
- Users can browse job listings and apply by submitting resumes
- Admins can post job opportunities and review applications
- RESTful API powered by Express & MongoDB
- Secure, token-based access control
- Backend deployed to **AWS EC2**
- Frontend built using **React** and **Vite**

**Code:** [mern-job-board](./mern-job-board)  
**Demo / Screenshots:** *(Include if available)*

---

### 2. Signature Verification (Siamese Neural Networks)
Collaborative final project for the *Brain-Inspired AI* course (with Chinwe Aghadinuno).  
Goal: Use Siamese Neural Networks to verify handwritten signatures and detect forgeries using deep metric learning methods.

**Key Details:**
- Two Siamese architectures:
  - Custom ResNet-inspired CNN (64-dimensional embedding)
  - Modified pre-trained CNN (2-dimensional embedding)
- Training based on the contrastive loss function
- Dataset: 2,200 signature image pairs from the 2011 ICDAR dataset
- Custom model achieved **70% accuracy**, outperforming the pre-trained model (**30% accuracy**)

**Technologies Used:**
- PyTorch, NumPy, Pandas, Matplotlib, Scikit-learn
- Optimizers: Adam for custom model, RMSProp for pre-trained model
- Metrics: Accuracy, confusion matrix, TP/FP/FN analysis
- Training: ~1 hour (GPU) for custom CNN; ~2.5 hours for pre-trained CNN

**Code:** [signature-classification](./signature-classification)

---

### 3. REST API (Go)
A clean and lightweight RESTful API built in **Go**, showcasing backend fundamentals and idiomatic coding practices.

**Features:**
- Implements standard CRUD operations
- Organized using Go modules
- Designed with clear separation of routes, handlers, and models
- Easily extendable to use a persistent database
- Followed RESTful endpoint conventions


