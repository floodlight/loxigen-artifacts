// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_class.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver12;

import org.projectfloodlight.openflow.protocol.*;
import org.projectfloodlight.openflow.protocol.action.*;
import org.projectfloodlight.openflow.protocol.actionid.*;
import org.projectfloodlight.openflow.protocol.bsntlv.*;
import org.projectfloodlight.openflow.protocol.errormsg.*;
import org.projectfloodlight.openflow.protocol.meterband.*;
import org.projectfloodlight.openflow.protocol.instruction.*;
import org.projectfloodlight.openflow.protocol.instructionid.*;
import org.projectfloodlight.openflow.protocol.match.*;
import org.projectfloodlight.openflow.protocol.stat.*;
import org.projectfloodlight.openflow.protocol.oxm.*;
import org.projectfloodlight.openflow.protocol.oxs.*;
import org.projectfloodlight.openflow.protocol.queueprop.*;
import org.projectfloodlight.openflow.types.*;
import org.projectfloodlight.openflow.util.*;
import org.projectfloodlight.openflow.exceptions.*;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.util.Set;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;

class OFOxmBsnIpFragmentationVer12 implements OFOxmBsnIpFragmentation {
    private static final Logger logger = LoggerFactory.getLogger(OFOxmBsnIpFragmentationVer12.class);
    // version: 1.2
    final static byte WIRE_VERSION = 3;
    final static int LENGTH = 5;

        private final static OFBooleanValue DEFAULT_VALUE = OFBooleanValue.FALSE;

    // OF message fields
    private final OFBooleanValue value;
//
    // Immutable default instance
    final static OFOxmBsnIpFragmentationVer12 DEFAULT = new OFOxmBsnIpFragmentationVer12(
        DEFAULT_VALUE
    );

    // package private constructor - used by readers, builders, and factory
    OFOxmBsnIpFragmentationVer12(OFBooleanValue value) {
        if(value == null) {
            throw new NullPointerException("OFOxmBsnIpFragmentationVer12: property value cannot be null");
        }
        this.value = value;
    }

    // Accessors for OF message fields
    @Override
    public long getTypeLen() {
        return 0x33401L;
    }

    @Override
    public OFBooleanValue getValue() {
        return value;
    }

    @Override
    public MatchField<OFBooleanValue> getMatchField() {
        return MatchField.BSN_IP_FRAGMENTATION;
    }

    @Override
    public boolean isMasked() {
        return false;
    }

    public OFOxm<OFBooleanValue> getCanonical() {
        // exact match OXM is always canonical
        return this;
    }

    @Override
    public OFBooleanValue getMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property mask not supported in version 1.2");
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_12;
    }



    public OFOxmBsnIpFragmentation.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFOxmBsnIpFragmentation.Builder {
        final OFOxmBsnIpFragmentationVer12 parentMessage;

        // OF message fields
        private boolean valueSet;
        private OFBooleanValue value;

        BuilderWithParent(OFOxmBsnIpFragmentationVer12 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public long getTypeLen() {
        return 0x33401L;
    }

    @Override
    public OFBooleanValue getValue() {
        return value;
    }

    @Override
    public OFOxmBsnIpFragmentation.Builder setValue(OFBooleanValue value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public MatchField<OFBooleanValue> getMatchField() {
        return MatchField.BSN_IP_FRAGMENTATION;
    }

    @Override
    public boolean isMasked() {
        return false;
    }

    @Override
    public OFOxm<OFBooleanValue> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.2");
    }

    @Override
    public OFBooleanValue getMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property mask not supported in version 1.2");
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_12;
    }



        @Override
        public OFOxmBsnIpFragmentation build() {
                OFBooleanValue value = this.valueSet ? this.value : parentMessage.value;
                if(value == null)
                    throw new NullPointerException("Property value must not be null");

                //
                return new OFOxmBsnIpFragmentationVer12(
                    value
                );
        }

    }

    static class Builder implements OFOxmBsnIpFragmentation.Builder {
        // OF message fields
        private boolean valueSet;
        private OFBooleanValue value;

    @Override
    public long getTypeLen() {
        return 0x33401L;
    }

    @Override
    public OFBooleanValue getValue() {
        return value;
    }

    @Override
    public OFOxmBsnIpFragmentation.Builder setValue(OFBooleanValue value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public MatchField<OFBooleanValue> getMatchField() {
        return MatchField.BSN_IP_FRAGMENTATION;
    }

    @Override
    public boolean isMasked() {
        return false;
    }

    @Override
    public OFOxm<OFBooleanValue> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.2");
    }

    @Override
    public OFBooleanValue getMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property mask not supported in version 1.2");
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_12;
    }

//
        @Override
        public OFOxmBsnIpFragmentation build() {
            OFBooleanValue value = this.valueSet ? this.value : DEFAULT_VALUE;
            if(value == null)
                throw new NullPointerException("Property value must not be null");


            return new OFOxmBsnIpFragmentationVer12(
                    value
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader extends AbstractOFMessageReader<OFOxmBsnIpFragmentation> {
        @Override
        public OFOxmBsnIpFragmentation readFrom(OFMessageReaderContext context, ByteBuf bb) throws OFParseError {
            if(bb.readableBytes() < LENGTH)
                return null;
            // fixed value property typeLen == 0x33401L
            int typeLen = bb.readInt();
            if(typeLen != 0x33401)
                throw new OFParseError("Wrong typeLen: Expected=0x33401L(0x33401L), got="+typeLen);
            OFBooleanValue value = OFBooleanValue.of(bb.readByte() != 0);

            OFOxmBsnIpFragmentationVer12 oxmBsnIpFragmentationVer12 = new OFOxmBsnIpFragmentationVer12(
                    value
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", oxmBsnIpFragmentationVer12);
            return oxmBsnIpFragmentationVer12;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFOxmBsnIpFragmentationVer12Funnel FUNNEL = new OFOxmBsnIpFragmentationVer12Funnel();
    static class OFOxmBsnIpFragmentationVer12Funnel implements Funnel<OFOxmBsnIpFragmentationVer12> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFOxmBsnIpFragmentationVer12 message, PrimitiveSink sink) {
            // fixed value property typeLen = 0x33401L
            sink.putInt(0x33401);
            message.value.putTo(sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFOxmBsnIpFragmentationVer12> {
        @Override
        public void write(ByteBuf bb, OFOxmBsnIpFragmentationVer12 message) {
            // fixed value property typeLen = 0x33401L
            bb.writeInt(0x33401);
            bb.writeByte(message.value.getInt());


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFOxmBsnIpFragmentationVer12(");
        b.append("value=").append(value);
        b.append(")");
        return b.toString();
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        OFOxmBsnIpFragmentationVer12 other = (OFOxmBsnIpFragmentationVer12) obj;

        if (value == null) {
            if (other.value != null)
                return false;
        } else if (!value.equals(other.value))
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime * result + ((value == null) ? 0 : value.hashCode());
        return result;
    }

}
