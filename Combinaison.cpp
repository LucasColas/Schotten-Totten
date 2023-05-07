#include "Combinaison.h"



bool Combinaison::estUneCouleur3(){
    Couleur C1= c1->get_couleur();
    Couleur C2= c2->get_couleur();
    Couleur C3= c3->get_couleur();

    return (C1==C2 && C2==C3);
}

bool Combinaison::estUneCouleur4(){
    Couleur C1= c1->get_couleur();
    Couleur C2= c2->get_couleur();
    Couleur C3= c3->get_couleur();
    Couleur C4= c4->get_couleur();

    return (C1==C2 && C2==C3 && C3==C4);
}



bool Combinaison::estUneSuite3(){
    int v1=c1->get_force();
    int v2=c2->get_force();
    int v3=c3->get_force();

    bool r1,r2;
    r1=(v1*2==v2+v3-3 || v2*2==v1+v3-3 || v3*2== v1+v2-3);
    r2=(v1!=v2 && v1!=v3 && v2!= v3);

    return (r1 && r2);
}

bool Combinaison::estUneSuite4(){
    int v1=c1->get_force();
    int v2=c2->get_force();
    int v3=c3->get_force();
    int v4=c4->get_force();
    
    bool r1, r2;
    r1 = (v1*3==v2+v3+v4-6 || v2*3==v1+v3+v4-6 || v3*3== v1+v2+v4-6 || v4*3== v1+v2+v3-6);
    r2 = (v1!= v2 && v1!= v3 && v1!= v4 && v2!= v3 && v2!= v4 && v3!= v4);

    return (r1 && r2);
}





bool Combinaison::estUnBrelan3(){
    int v1=c1->get_force();
    int v2=c2->get_force();
    int v3=c3->get_force();

    return (v1==v2 && v2==v3);
}

bool Combinaison::estUnBrelan4(){
    int v1=c1->get_force();
    int v2=c2->get_force();
    int v3=c3->get_force();
    int v4=c4->get_force();

    return (v1==v2 && v2==v3 && v3==v4);
}


bool Combinaison::estUneSuiteCouleur3(){
    return (estUneCouleur3() && estUneSuite3());
}
bool Combinaison::estUneSuiteCouleur4(){
    return (estUneCouleur4() && estUneSuite4());
}




void Combinaison::PuissanceCombinaison(){
    if (nb_carte==3) {
        
        int p=c1->get_force() + c2->get_force() + c3->get_force();

        if (estUneSuiteCouleur3()) p=p+10000;
        if (estUnBrelan3()) p=p+10000;
        if (estUneCouleur3()) p=p+1000;
        if (estUneSuite3()) p=p+100;
        Puissance=p;
    }
    if (nb_carte==4) {
        
        int p=c1->get_force() + c2->get_force() + c3->get_force() + c4->get_force();

        if (estUneSuiteCouleur4()) p=p+10000;
        if (estUnBrelan4()) p=p+10000;
        if (estUneCouleur4()) p=p+1000;
        if (estUneSuite4()) p=p+100;
        Puissance=p;
    }




    
};

