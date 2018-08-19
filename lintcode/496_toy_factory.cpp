/**
 * Your object will be instantiated and called as such:
 * ToyFactory* tf = new ToyFactory();
 * Toy* toy = tf->getToy(type);
 * toy->talk();
 */

class Toy {
    public:
        virtual void talk() const=0;
};



class Dog: public Toy {
    void talk() const override {
        cout << "Wow" << endl;  
    }
};

class Cat: public Toy {
    void talk() const override {
        cout << "Meow" << endl;  
    }
};

class PetToyFactory {
    public:
        virtual unique_ptr<Toy> make() = 0;
};

class DogFactory: public PetToyFactory {
    public:
        unique_ptr<Toy> make() override {
            return make_unique<Dog>();
        }
};

class CatFactory: public PetToyFactory {
    public:
        unique_ptr<Toy> make() override {
            return make_unique<Cat>();
        }
};

class ToyFactory {
    public:
        /**
         * @param type a string
         * @return Get object of the type
         */
        map <string, unique_ptr<PetToyFactory>> factories;

        ToyFactory() {
            factories["Dog"] = make_unique<DogFactory>();
            factories["Cat"] = make_unique<CatFactory>();
        }

        Toy* getToy(string const& type) {
            auto toy = factories[type]->make();
            return toy.release();
        }
};
