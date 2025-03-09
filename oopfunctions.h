#pragma once

class Airplane {
private:
    int _id;
    char* _model;
    char* _color;
    double _engine;
    int _capacity;
    static int _staticId;
    static int _MAXCOUNT;

public:
    explicit Airplane(const char* model, const char* color, double engine, int capacity): _engine(engine), _capacity(capacity), _model(nullptr), _color(nullptr) {
        _model = new char[strlen(model) + 1];
        strcpy_s(_model, strlen(model) + 1, model);

        _color = new char[strlen(color) + 1];
        strcpy_s(_color, strlen(color) + 1, color);

        _id = _staticId++;

        assert(_staticId <= _MAXCOUNT && "Exceeded maximum number of airplanes.");
    }

    ~Airplane() {
        delete[] _model;
        delete[] _color;
    }

    void print() {
		cout << "***********************" << "\n";
        cout << "Airplane ID: " << _id << "\n"
            << "Model: " << _model << "\n"
            << "Color: " << _color << "\n"
            << "Engine: " << _engine << "\n"
            << "Capacity: " << _capacity << "\n";
		cout << "***********************" << "\n";
    }

    int getId() const { return _id; }
    const char* getModel()  { return _model; }
    const char* getColor()  { return _color; }
    double getEngine() const  { return _engine; }
    int getCapacity() const { return _capacity; }

    static void setMaxCount(int count) {
        _MAXCOUNT = count;
    }

    static int getMaxCount() {
        return _MAXCOUNT;
    }
};

int Airplane::_staticId = 1;
int Airplane::_MAXCOUNT = 100;

class Garage {
private:
    Airplane** airplanes;
    size_t _count;
    char* _name;
    char* _address;

public:
    explicit Garage(const char* name, const char* address): _count(0), airplanes(nullptr), _name(nullptr), _address(nullptr) {
        _name = new char[strlen(name) + 1];
        strcpy_s(_name, strlen(name) + 1, name);

        _address = new char[strlen(address) + 1];
        strcpy_s(_address, strlen(address) + 1, address);
    }

    ~Garage() {
        for (size_t i = 0; i < _count; ++i) {
            delete airplanes[i];
        }
        delete[] airplanes;
        delete[] _name;
        delete[] _address;
    }

    void addAirplane(Airplane* airplane) {
        Airplane** newAirplanes = new Airplane * [_count + 1];
        for (size_t i = 0; i < _count; ++i) {
            newAirplanes[i] = airplanes[i];
        }
        newAirplanes[_count] = airplane;
        ++_count;

        delete[] airplanes;
        airplanes = newAirplanes;
    }

    Airplane* getAirplaneById(int id) {
        for (size_t i = 0; i < _count; ++i) {
            if (airplanes[i]->getId() == id) {
                return airplanes[i];
            }
        }
        return nullptr;
    }

    Airplane** getAirplanesCapacityGreaterThan(int capacity) {
        size_t resultCount = 0;
        for (size_t i = 0; i < _count; ++i) {
            if (airplanes[i]->getCapacity() > capacity) {
                ++resultCount;
            }
        }

        if (resultCount == 0) return nullptr;

        Airplane** result = new Airplane * [resultCount + 1];
        size_t idx = 0;
        for (size_t i = 0; i < _count; ++i) {
            if (airplanes[i]->getCapacity() > capacity) {
                result[idx++] = airplanes[i];
            }
        }

        result[idx] = nullptr;
        return result;
    }

    Airplane** getAirplanesByColor(const char* color) {
        size_t resultCount = 0;
        for (size_t i = 0; i < _count; ++i) {
            if (strcmp(airplanes[i]->getColor(), color) == 0) {
                ++resultCount;
            }
        }

        if (resultCount == 0) return nullptr;

        Airplane** result = new Airplane * [resultCount + 1];
        size_t idx = 0;
        for (size_t i = 0; i < _count; ++i) {
            if (strcmp(airplanes[i]->getColor(), color) == 0) {
                result[idx++] = airplanes[i];
            }
        }

        result[idx] = nullptr;
        return result;
    }

    void print() {
        cout << "Garage Name: " << _name << "\n"
            << "Address: " << _address << "\n"
            << "Airplanes: " << _count << "\n";
        for (size_t i = 0; i < _count; ++i) {
            airplanes[i]->print();
        }
    }

    const char* getName() { return _name; }
    const char* getAddress() { return _address; }
    size_t getAirplaneCount() const { return _count; }
};





