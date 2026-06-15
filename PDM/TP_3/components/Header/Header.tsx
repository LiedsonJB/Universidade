import { Image, Text } from 'react-native';
import Styles from './Header.style';

const Header = () => {
    return (
        <>
            <Image
                style={Styles.img}
                source={require('../../assets/temkfaze.png')}
                resizeMode="contain"
            />
            <Text style={Styles.subtitle}>Enton fazê!</Text>
        </>
    );
};

export default Header;