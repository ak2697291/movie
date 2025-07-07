package linkedList.ChessLLD;

public class BoardSquare {
    /*
     *  *BoardSquare
    -String: color
    - boolean : isOccupied
    - ChessPiece: chessPiece
    - int:x
    - int:y
     */


     private boolean isOccupied;
     private ChessPiece chessPiece;
     private int xCoordinate;
     private int yCoordinate;

     BoardSquare( boolean isOccupied, ChessPiece chessPiece, int xCoordinate, int yCoordinate){

        this.isOccupied = isOccupied;
        this.chessPiece = chessPiece;
        this.xCoordinate = xCoordinate;
        this.yCoordinate = yCoordinate;
     }

     public ChessPiece getChessPiece() {
         return chessPiece;
     }public void setChessPiece(ChessPiece chessPiece) {
         this.chessPiece = chessPiece;
     }public int getxCoordinate() {
         return xCoordinate;
     }public void setxCoordinate(int xCoordinate) {
         this.xCoordinate = xCoordinate;
     }public int getyCoordinate() {
         return yCoordinate;
     }public void setyCoordinate(int yCoordinate) {
         this.yCoordinate = yCoordinate;
     }public void setOccupied(boolean isOccupied) {
         this.isOccupied = isOccupied;
     }
    public boolean getIsOccupied(){
        return this.isOccupied;
    }


}
