#include <dwt2d.hpp>
#include <matrix.hpp>
#include <util.hpp>


int main() {
    Matrix img = load_cringe_img("tmp/shrek.txt");
    DWT2D::foward(img, 2);
    save_cringe_img("tmp/shrek_dwt.txt", img);
    return 0;
}