import robocode.*;
import java.awt.Color;

public class MyRobo {

        public class RoboEstrategico extends AdvancedRobot {
            @Override
            public void run() {
                // Definição da cor do robô
                setColors(Color.BLUE, Color.RED, Color.YELLOW); // Corpo, arma e radar

                while (true) {
                    turnRadarRight(360); // Mantém o radar ativo
                }
            }

            @Override
            public void onScannedRobot(ScannedRobotEvent e) {
                double distancia = e.getDistance();
                double energiaInimigo = e.getEnergy();

                if (distancia < 100) {
                    setFire(3); // Tiro forte se estiver perto
                } else {
                    setFire(1); // Tiro fraco se estiver longe
                }

                if (energiaInimigo > getEnergy()) { // Se o inimigo for mais forte, fugir
                    fugir();
                } else { // Senão, atacar estrategicamente
                    atacar(e);
                }

                execute();
            }

            @Override
            public void onHitByBullet(HitByBulletEvent e) {
                fugir(); // Se for atingido, fugir e reposicionar
            }

            private void fugir() {
                setTurnRight(90);
                setAhead(200); // Move para longe do perigo
            }

            private void atacar(ScannedRobotEvent e) {
                setTurnGunRight(getHeading() - getGunHeading() + e.getBearing());
                setAhead(e.getDistance() / 2);
            }
        }

}
