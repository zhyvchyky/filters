//
// Created by linups on 11/28/20.
//
#include "utilities/applyVectorTransform.h"

Pixel applyVectorTransform(const std::shared_ptr<Image>& img1, int row, int col, Mode mode, int centre, double* transformVector){
    Pixel result;
    int begin;
    int width = img1->getWidth();
    int height = img1->getHeight();

    if(mode == Horizontal){             //розрахунок пікселя при горизонтальній орієнтації вагового масиву
        begin = abs(centre - col);       //початок відліку
        if(centre >= col){               //якщо центр вагового вектора(oneDimTransform) більше колонки => begin - початок відліку в OneDimTransform
            for(int i = begin; i < 2*centre + 1; i++){
                if(i-begin == width){
                    break;
                }
                result = result + (img1->getPixel(row,i-begin) * transformVector[i]);
            }
        }
        else{               //інакше begin - початок відліку в рядку row матриці пікселів
            for(int i = begin; i < 2*centre + 1 + begin; i++){
                if(i == width){
                    break;
                }
                result = result + (img1->getPixel(row,i) * transformVector[i-begin]);
            }
        }
    }

    else if(mode == Vertical){          //розрахунок пікселя при вертикальній орієнтації вагового масиву
        begin = abs(centre - row);
        if(centre >= row){
            for(int i = begin; i < 2*centre + 1; i++){
                if(i-begin == height){
                    break;
                }
                result = result + (img1->getPixel(i-begin,col) * transformVector[i]);
            }
        }
        else{
            for(int i = begin; i < 2*centre + 1 + begin; i++){
                if(i == height){
                    break;
                }
                result = result + (img1->getPixel(i,col) * transformVector[i-begin]);
            }
        }
    }
    return result;
}
