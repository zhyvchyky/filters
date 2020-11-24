//
// Created by linups on 11/21/20.
//

#include "GaussianBlurProcessor.h"

GaussianBlurProcessor::GaussianBlurProcessor(int N) {
    //TODO raise error if N(radius of blur) > 100 or N <= 0
    this->N = N;
}

void GaussianBlurProcessor::process() {     //розраховує gaussian kernel
    double weights[2*N+1];
    weights[N] = 1.;                //додамо до масиву вагу центрального елементу
    scale = 1.;                                 //також додамо значення центрального елементу

    for(int weight = 1; weight < N+1; ++weight){
        double x = 3. * double (weight)/double (N);         //розраховуємо опорні точки
        double Gval = exp(-x * x/2.);                   //розраховуємо значення функції в опорних точках
        weights[N + weight] = weights[N - weight] = Gval;   //kernel симетричний тому однакові значення будуть на симетричних позиціях
        scale += 2. * Gval;
    }

    for(int i = 0; i < 2*N + 1; i++){
        weights[i] /= scale;                    //нормуємо розраховані вагові значення
        oneDimTransform.push_back(weights[i]);
    }
}

void GaussianBlurProcessor::applyTransform(Image img1) {  //застосовуємо фільтр як композицію двох: по вісі х і по вісі у
    int width = img1.getWidth();
    int height = img1.getHeight();
    Image img2 = Image(height, width, 3, new Pixel[height * width]);

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            Pixel pixel = calculatePixel(img1, i, j, Mode::Horizontal);
            img2.setPixel(i, j, pixel.red, pixel.green, pixel.blue);
        }
    }

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            Pixel pixel = calculatePixel(img2, i, j, Mode::Vertical);
            img1.setPixel(i, j, pixel.red, pixel.green, pixel.blue);
        }
    }
}

Pixel GaussianBlurProcessor::calculatePixel(Image img1, int row, int col, GaussianBlurProcessor::Mode mode) {
    Pixel result;
    int begin;
    int width = img1.getWidth();
    int height = img1.getHeight();

    if(mode == Horizontal){             //розрахунок пікселя при горизонтальній орієнтації вагового масиву
        begin = abs(N - col);       //початок відліку
        if(N >= col){               //якщо центр вагового вектора(oneDimTransform) більше колонки => begin - початок відліку в OneDimTransform
            for(int i = begin; i < 2*N + 1; i++){
                if(i-begin == width){
                    break;
                }
                result = result + (img1.getPixel(row,i-begin) * oneDimTransform[i]);
            }
        }
        else{               //інакше begin - початок відліку в рядку row матриці пікселів
            for(int i = begin; i < 2*N + 1 + begin; i++){
                if(i == width){
                    break;
                }
                result = result + (img1.getPixel(row,i) * oneDimTransform[i-begin]);
            }
        }
    }

    else if(mode == Vertical){          //розрахунок пікселя при вертикальній орієнтації вагового масиву
        begin = abs(N - row);
        if(N >= row){
            for(int i = begin; i < 2*N + 1; i++){
                if(i-begin == height){
                    break;
                }
                result = result + (img1.getPixel(i-begin,col) * oneDimTransform[i]);
            }
        }
        else{
            for(int i = begin; i < 2*N + 1 + begin; i++){
                if(i == height){
                    break;
                }
                result = result + (img1.getPixel(i,col) * oneDimTransform[i-begin]);
            }
        }
    }
    return result;
}
