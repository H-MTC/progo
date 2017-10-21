package com.progo;
import com.dkriesel.snipe.core.NeuralNetwork;
import com.dkriesel.snipe.core.NeuralNetworkDescriptor;
public class progo {
	public static void main(String args[]) {
		int[] a = {2,4,3,5,7};
		NeuralNetwork net = new NeuralNetwork(new NeuralNetworkDescriptor(a));
		net.createNeuronInRandomLayer();
		int layers = net.countLayers();
		int sys = net.countSynapses();
		System.out.println(layers + ',' + sys + ',' + net.toString());
		}
}
