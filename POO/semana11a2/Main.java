public class Main {
    public static void main(String[] args) {
        AnimalMonitor animalMonitor = new AnimalMonitor();
        animalMonitor.addSightings("sightings.csv");

        animalMonitor.printList();
    }
}
