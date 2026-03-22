/*
DESCRIEREA PROBLEMEI:
Acest program gestioneaza si evalueaza configuratii Hardware (PC-uri).
OPERATII POSIBILE:
Crearea, copierea profunda (deep copy) si atribuirea sistemelor.
Afisarea detaliata prin compunerea operatorului <<.
Calcularea unui scor de performanta global.
Verificarea unui bottleneck intre componente.
 */

#include <iostream>
#include <cstring>

//CLASA PROCESOR
class Procesor {
private:
    float GHz;
    char* nume;
    int generatie;

public:
    // Constructor de initializare
    Procesor(const char* nume = "Unknown", int generatie = 0, float GHz = 0.0f) {
        this->GHz = GHz;
        this->generatie = generatie;
        this->nume = new char[std::strlen(nume) + 1];
        std::strcpy(this->nume, nume);
    }

    // Constructor de copiere
    Procesor(const Procesor& other) {
        this->GHz = other.GHz;
        this->generatie = other.generatie;
        this->nume = new char[std::strlen(other.nume) + 1];
        std::strcpy(this->nume, other.nume);
    }

    // Operator de atribuire
    Procesor& operator=(const Procesor& other) {
        if (this != &other) {
            delete[] this->nume;
            this->GHz = other.GHz;
            this->generatie = other.generatie;
            this->nume = new char[std::strlen(other.nume) + 1];
            std::strcpy(this->nume, other.nume);
        }
        return *this;
    }

    // Destructor
    ~Procesor() {
        delete[] this->nume;
    }

    // Getteri
    const char* getNume() const { return this->nume; }
    float getGhz() const { return this->GHz; }
    int getGeneratie() const { return this->generatie; }

    // Setteri
    void setNume(const char* nume) {
        delete[] this->nume;
        this->nume = new char[std::strlen(nume) + 1];
        std::strcpy(this->nume, nume);
    }
    void setGeneratie(const int& generatie) { this->generatie = generatie; }
    void setGhz(const float& GHz) { this->GHz = GHz; }

    // Operator <<
    friend std::ostream& operator<<(std::ostream& out, const Procesor& p) {
        out <<"CPU: " << p.nume << std::endl<<"Gen: " << p.generatie << std::endl<< p.GHz << " GHz";
        return out;
    }
};

//CLASA VIDEO
class Video {
private:
    char* firma;
    char* tehnologie;
    int generatie;
    int ram;
    float GHz;

public:
    // Constructor de initializare
    Video(const char* firma = "Unknown", const char* tehnologie = "Unknown", int generatie = 0, int ram = 0, float GHz = 0.0f) {
        this->generatie = generatie;
        this->ram = ram;
        this->GHz = GHz;
        this->firma = new char[std::strlen(firma) + 1];
        std::strcpy(this->firma, firma);
        this->tehnologie = new char[std::strlen(tehnologie) + 1];
        std::strcpy(this->tehnologie, tehnologie);
    }

    // Constructor de copiere
    Video(const Video& other) {
        this->generatie = other.generatie;
        this->ram = other.ram;
        this->GHz = other.GHz;
        this->firma = new char[std::strlen(other.firma) + 1];
        std::strcpy(this->firma, other.firma);
        this->tehnologie = new char[std::strlen(other.tehnologie) + 1];
        std::strcpy(this->tehnologie, other.tehnologie);
    }

    // Operator de atribuire
    Video& operator=(const Video& other) {
        if (this != &other) {
            delete[] this->firma;
            delete[] this->tehnologie;
            this->generatie = other.generatie;
            this->ram = other.ram;
            this->GHz = other.GHz;

            this->firma = new char[std::strlen(other.firma) + 1];
            std::strcpy(this->firma, other.firma);
            this->tehnologie = new char[std::strlen(other.tehnologie) + 1];
            std::strcpy(this->tehnologie, other.tehnologie);
        }
        return *this;
    }

    // Destructor
    ~Video() {
        delete[] this->firma;
        delete[] this->tehnologie;
    }

    // Getteri
    const char* getFirma() const { return this->firma; }
    const char* getTehnologie() const { return this->tehnologie; }
    float getGhz() const { return this->GHz; }
    int getGeneratie() const { return this->generatie; }
    int getRam() const { return this->ram; }

    // Setteri
    void setFirma(const char* firma) {
        delete[] this->firma;
        this->firma = new char[std::strlen(firma) + 1];
        std::strcpy(this->firma, firma);
    }
    void setTehnologie(const char* tehnologie) {
        delete[] this->tehnologie;
        this->tehnologie = new char[std::strlen(tehnologie) + 1];
        std::strcpy(this->tehnologie, tehnologie);
    }
    void setGeneratie(const int& generatie) { this->generatie = generatie; }
    void setRam(const int& ram) { this->ram = ram; }
    void setGhz(const float& GHz) { this->GHz = GHz; }

    // Operator <<
    friend std::ostream& operator<<(std::ostream& out, const Video& v) {
        out <<"GPU: " << v.firma << std::endl << v.tehnologie << " "<< v.generatie
            << std::endl << v.ram << "GB VRAM" <<std::endl<< v.GHz << " GHz";
        return out;
    }
};

//CLASA HARDWARE
class Hardware {
private:
    Procesor cpu;
    Video gpu;
    int performanta;
    char* nume;



public:
    // Constructor de initializare
    Hardware(const char* nume = "Sistem_Default", const Procesor& p = Procesor(), const Video& v = Video(), int performanta = 0) {
        this->cpu = p;
        this->gpu = v;
        this->performanta = performanta;
        this->nume = new char[std::strlen(nume) + 1];
        std::strcpy(this->nume, nume);
    }

    // Constructor de copiere
    Hardware(const Hardware& other) {
        this->cpu = other.cpu;
        this->gpu = other.gpu;
        this->performanta = other.performanta;
        this->nume = new char[std::strlen(other.nume) + 1];
        std::strcpy(this->nume, other.nume);
    }

    // Operator de atribuire
    Hardware& operator=(const Hardware& other) {
        if (this != &other) {
            delete[] this->nume;
            this->cpu = other.cpu;
            this->gpu = other.gpu;
            this->performanta = other.performanta;

            this->nume = new char[std::strlen(other.nume) + 1];
            std::strcpy(this->nume, other.nume);
        }
        return *this;
    }

    // Destructor
    ~Hardware() {
        delete[] this->nume;
    }

    // Getteri
    const char* getNume() const { return this->nume; }
    int getPerformanta() const { return this->performanta; }
    Procesor getProcesor() const { return this->cpu; }
    Video getVideo() const { return this->gpu; }

    // Setteri
    void setNume(const char* nume) {
        delete[] this->nume;
        this->nume = new char[std::strlen(nume) + 1];
        std::strcpy(this->nume, nume);
    }
    void setPerformanta(const int& performanta) { this->performanta = performanta; }
    void setProcesor(const Procesor& cpu) { this->cpu = cpu; }
    void setVideo(const Video& gpu) { this->gpu = gpu; }

    // Calcularea Performantei Calculatorului

    float calculeazaScorPerformanta() {
        float scor = (this->cpu.getGhz() * this->cpu.getGeneratie() * 10) + (this->gpu.getRam() * this->gpu.getGhz() * 5);
        this->performanta = scor;
        return scor;
    }



    const char* verificaBottleneck() const {
        if (this->cpu.getGeneratie() < 5 && this->gpu.getRam() >= 12) {
            return "Procesorul creeaza bottleneck (limiteaza placa video).";
        }
        if (this->cpu.getGeneratie() >= 9 && this->gpu.getRam() < 6) {
            return "Placa video creeaza bottleneck (limiteaza procesorul).";
        }
        return "Sistem echilibrat, nu exista bottleneck major.";
    }

    friend std::ostream& operator<<(std::ostream& out, const Hardware& h) {
        out << " Sistem Hardware: " << h.nume << std::endl << h.cpu << std::endl << h.gpu << std::endl << "Scor Performanta:" << h.performanta ;

        return out;
    }
};

// FUNCTIA MAIN
int main() {
    Procesor p1("Ryzen_3", 4, 3.8f);
    Video v1("Nvidia", "RTX", 4070, 12, 2.5f);
    Hardware pc1("Gaming_PC", p1, v1);
    pc1.calculeazaScorPerformanta();
    std::cout << pc1 << std::endl << std::endl;

    std::cout << "VERIFICARE BOTTLENECK ";
    std::cout << pc1.verificaBottleneck() << std::endl << std::endl;

    Hardware pc2 = pc1; // Apeleaza constructorul de copiere
    Hardware pc3;
    pc3 = pc1;          // Apeleaza operatorul de atribuire
    // Testare Getteri si Setteri
    pc3.setNume("Office_PC");
    pc3.setPerformanta(1500);

    Procesor p2("Intel_i3", 10, 3.1f);
    pc3.setProcesor(p2); // Inlocuim procesorul

    std::cout << "TEST GETTERI SI SETTERI (PC MODIFICAT)" << std::endl ;
    std::cout << "Nume: " << pc3.getNume() << std::endl ;
    std::cout << "Nume NOU Procesor: " << pc3.getProcesor().getNume() << std::endl ;
    std::cout << "Performanta manuala: " << pc3.getPerformanta() << std::endl ;

    return 0;
}
