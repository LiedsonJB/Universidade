import java.util.ArrayList;
import java.util.Iterator;

/**
 * Monitoriza contagens de diferentes tipos de animais.
 * As observações são registadas por observadores.
 * 
 * @author David J. Barnes e Michael Kölling
 * @version 2016.02.29 (imperativo)
 */
public class AnimalMonitor 
{
    // Registos de todas as observações de animais.
    private ArrayList<Sighting> sightings;
    
    /**
     * Cria um monitor de animais.
     */
    public AnimalMonitor()
    {
        this.sightings = new ArrayList<>();
    }
    
    /**
     * Adiciona as observações registadas no ficheiro indicado à lista atual.
     * @param filename Um ficheiro CSV com registos de observações.
     */
    public void addSightings(String filename)
    {
        SightingReader reader = new SightingReader();
        sightings.addAll(reader.getSightings(filename));
    }
    
    /**
     * Imprime os detalhes de todas as observações.
     */
    public void printList()
    {
       /* for(Sighting record : sightings) {
            System.out.println(record.getDetails());
        }*/
        sightings.forEach(
                (record) -> System.out.println(record.getDetails())
        );
    }
    
    /**
     * Imprime os detalhes de todas as observações do animal indicado.
     * @param animal O tipo de animal.
     */
    public void printSightingsOf(String animal)
    {

        sightings.stream().filter(record -> animal.equals(record.getAnimal()))
                .forEach(s -> System.out.println(s.getDetails())
                );

        /*sightings.forEach((record)->{
            if(animal.equals(record.getAnimal())) {
                System.out.println(record.getDetails());
            }
        });*/

        /*for(Sighting record : sightings) {
            if(animal.equals(record.getAnimal())) {
                System.out.println(record.getDetails());
            }
        }*/
    }
    
    /**
     * Imprime todas as observações feitas pelo observador indicado.
     * @param spotter O ID do observador.
     */
    public void printSightingsBy(int spotter)
    {
        sightings.stream().filter(record -> record.getSpotter() == spotter).forEach(a -> System.out.println(a.getSpotter()));
        /*for(Sighting record : sightings) {
            if(record.getSpotter() == spotter) {
                System.out.println(record.getDetails());
            }
        }        */
    }

    public void detalhesDia(int dayID){
        sightings.stream().filter(dia -> dia.getPeriod() == dayID).
                forEach(a -> System.out.println(a.getPeriod()));
    }

    public void detalhesObservacao(int obs){
        /*sightings.stream().filter(o -> o.getCount() < obs)
                .forEach(o -> System.out.println(o.getDetails())
                );*/

        sightings.stream().filter(s -> s.getCount()<obs).map(a -> a.getCount())
                .reduce(0, (total, count) -> (total + count));
    }

    /**
     * Imprime uma lista dos tipos de animais considerados em perigo.
     * @param animalNames Uma lista de nomes de animais.
     * @param dangerThreshold Contagens inferiores ou iguais a este valor
     *                        são consideradas perigosas.
     */
    public void printEndangered(ArrayList<String> animalNames, int dangerThreshold)
    {
        for(String animal : animalNames) {
            if(getCount(animal) <= dangerThreshold) {
                System.out.println(animal + " está em perigo.");
            }
        }
    }
    
    /**
     * Devolve o número total de observações do animal indicado.
     * @param animal O tipo de animal.
     * @return A contagem de observações do animal indicado.
     */
    public int getCount(String animal)
    {
        int total = 0;
        for(Sighting sighting : sightings) {
            if(animal.equals(sighting.getAnimal())) {
                total = total + sighting.getCount();
            }
        }
        return total;
    }
    
    /**
     * Remove da lista de observações todos os registos com
     * contagem igual a zero.
     */
    public void removeZeroCounts()
    {
        Iterator<Sighting> it = sightings.iterator();
        while(it.hasNext()) {
            Sighting record = it.next();
            if(record.getCount() == 0) {
                it.remove();
            }
        }
    }
    
    /**
     * Devolve uma lista de todas as observações do tipo de animal indicado
     * numa área específica.
     * @param animal O tipo de animal.
     * @param area O ID da área.
     * @return Uma lista de observações.
     */
    public ArrayList<Sighting> getSightingsInArea(String animal, int area)
    {
        ArrayList<Sighting> records = new ArrayList<>();
        for(Sighting record : sightings) {
            if(animal.equals(record.getAnimal())) {
                if(record.getArea() == area) {
                    records.add(record);
                }
            }
        }
        return records;
    }
    
    /**
     * Devolve uma lista de todas as observações do animal indicado.
     * @param animal O tipo de animal.
     * @return Uma lista de todas as observações do animal indicado.
     */
    public ArrayList<Sighting> getSightingsOf(String animal)
    {
        ArrayList<Sighting> filtered = new ArrayList<>();
        for(Sighting record : sightings) {
            if(animal.equals(record.getAnimal())) {
                filtered.add(record);
            }
        }
        return filtered;
    }
}

