public class Client {
    public static void main(String args[]) {

        try {
            EFactory factory;
            AirConditioner ac;
            Television tv;
            factory = (EFactory) XMLUtil.getBean("Haier");
            ac = factory.produceAirConditioner();
            ac.changeTemperature();
            tv = factory.produceTelevision();
            tv.play();
            factory = (EFactory) XMLUtil.getBean("TCL");
            ac = factory.produceAirConditioner();
            ac.changeTemperature();
            tv = factory.produceTelevision();
            tv.play();
        }
        catch (Exception e)
        {
            System.out.println(e.getMessage());
        }
    }
}