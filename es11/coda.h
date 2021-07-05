typedef int T;
struct NodoSCL {
    T info;
    struct NodoSCL *next;
    
};
typedef struct NodoSCL TipoNodo;
typedef TipoNodo* Coda;
T primo(Coda* c);
void outCoda(Coda* c);
Coda* codaVuota();
void inCoda(Coda* c, T e);
bool estVuota(Coda*c);
