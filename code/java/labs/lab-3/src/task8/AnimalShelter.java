package src.task8;
import java.util.ArrayList;
import java.util.List;

class AnimalShelter {
    private List<Dog> dogs = new ArrayList<>();
    private List<Animal> otherAnimals = new ArrayList<>();

    public void addAnimals(Dog dog) { dogs.add(dog); }
    public void addAnimals(Animal animal) { otherAnimals.add(animal); }

    public void printAnimalSounds(List<? extends Animal> animals) {
        for (Animal animal : animals) {
            animal.makeSound();
        }
    }

    public List<Dog> getDogs() { return dogs; }
    public List<Animal> getOtherAnimals() { return otherAnimals; }
}