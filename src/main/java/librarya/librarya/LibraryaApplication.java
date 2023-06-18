package librarya.librarya;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;
import javafx.scene.text.Font;

public class LibraryaApplication extends Application {

    public Scene scene;
    public FXMLLoader fxmlLoader= new FXMLLoader(LibraryaApplication.class.getResource("CreateAccount.fxml"));
    @Override
    public void start(Stage stage) throws IOException {
        scene = new Scene(fxmlLoader.load());
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}