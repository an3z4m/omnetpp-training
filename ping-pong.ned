//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

//
// TODO auto-generated type
//
simple Player
{
    gates:
        input in;
        output out;
}

network PingPongGame
{
    @display("bgb=227,175");
    submodules:
        p1: Player {
            @display("p=29,67");
        }
        p2: Player {

            @display("p=179,67");
        }
    connections:
        p1.out --> p2.in;
        p2.out --> p1.in;

}
